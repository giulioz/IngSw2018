#include "Network/Response.hpp"

#include <string>

static const char* statusMessage(int statusCode) {
  switch (statusCode) {
    case 206:
      return "Partial Content";
    case 301:
      return "Moved";
    case 302:
      return "Found";
    case 400:
      return "Bad Request";
    case 401:
      return "Unauthorized";
    case 403:
      return "Forbidden";
    case 404:
      return "Not Found";
    case 416:
      return "Requested Range Not Satisfiable";
    case 418:
      return "I'm a teapot";
    case 500:
      return "Internal Server Error";
    case 502:
      return "Bad Gateway";
    case 503:
      return "Service Unavailable";
    case 100:
      return "Continue";
    case 101:
      return "Switching Protocols";
    case 102:
      return "Processing";
    case 200:
      return "OK";
    case 201:
      return "Created";
    case 202:
      return "Accepted";
    case 203:
      return "Non-Authoritative Information";
    case 204:
      return "No Content";
    case 205:
      return "Reset Content";
    case 207:
      return "Multi-Status";
    case 208:
      return "Already Reported";
    case 226:
      return "IM Used";
    case 300:
      return "Multiple Choices";
    case 303:
      return "See Other";
    case 304:
      return "Not Modified";
    case 305:
      return "Use Proxy";
    case 306:
      return "Switch Proxy";
    case 307:
      return "Temporary Redirect";
    case 308:
      return "Permanent Redirect";
    case 402:
      return "Payment Required";
    case 405:
      return "Method Not Allowed";
    case 406:
      return "Not Acceptable";
    case 407:
      return "Proxy Authentication Required";
    case 408:
      return "Request Timeout";
    case 409:
      return "Conflict";
    case 410:
      return "Gone";
    case 411:
      return "Length Required";
    case 412:
      return "Precondition Failed";
    case 413:
      return "Payload Too Large";
    case 414:
      return "URI Too Long";
    case 415:
      return "Unsupported Media Type";
    case 417:
      return "Expectation Failed";
    case 422:
      return "Unprocessable Entity";
    case 423:
      return "Locked";
    case 424:
      return "Failed Dependency";
    case 426:
      return "Upgrade Required";
    case 428:
      return "Precondition Required";
    case 429:
      return "Too Many Requests";
    case 431:
      return "Request Header Fields Too Large";
    case 451:
      return "Unavailable For Legal Reasons";
    case 501:
      return "Not Implemented";
    case 504:
      return "Gateway Timeout";
    case 505:
      return "HTTP Version Not Supported";
    case 506:
      return "Variant Also Negotiates";
    case 507:
      return "Insufficient Storage";
    case 508:
      return "Loop Detected";
    case 510:
      return "Not Extended";
    case 511:
      return "Network Authentication Required";
    default:
      return "OK";
  }
}

Response::Response(struct mg_connection* connection) {
  this->connection = connection;
  this->statusSent = false;
  this->typeSent = false;
}

Response::~Response() {}

void Response::type(const char* mimeType) {
  if (!statusSent) {
    status(200);
  }

  mg_printf(connection, "Content-Type: %s\r\n", mimeType);
  this->typeSent = true;
}

void Response::append(const char* field, const char* value) {
  mg_printf(connection, "%s: %s\r\n", field, value);
}

void Response::status(int statusCode) {
  mg_printf(connection, "HTTP/1.1 %d %s\r\n", statusCode,
            statusMessage(statusCode));
  this->statusSent = true;
}

void Response::send(const void* content, long size) {
  if (!statusSent) {
    status(200);
  }

  if (!typeSent) {
    this->type("text/binary");
  }

  std::string tmp;
  tmp += "Content-Length: ";
  tmp += size;
  tmp += "\r\n";
  mg_send(connection, tmp.c_str(), tmp.length());
  mg_printf(connection, "Connection: close\r\n\r\n");
  mg_send(connection, content, size);
  connection->flags |= MG_F_SEND_AND_CLOSE;
}

void Response::send(const char* content) {
  if (!statusSent) {
    status(200);
  }

  if (!typeSent) {
    this->type("text/plain");
  }

  mg_printf(connection, "Content-Length: %" INT64_FMT "\r\n", strlen(content));
  mg_printf(connection, "Connection: close\r\n\r\n");
  mg_send(connection, content, strlen(content));
  connection->flags |= MG_F_SEND_AND_CLOSE;
}

void Response::json(const char* content) {
  this->type("application/json; charset=utf-8");
  this->send(content);
}

void Response::sendStatus(int statusCode) {
  this->status(statusCode);
  this->send(statusMessage(statusCode));
}
