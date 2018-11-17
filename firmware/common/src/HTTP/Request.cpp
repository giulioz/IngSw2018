#include "HTTP/Request.hpp"

Request::Request(struct http_message *hm) {
  if (hm->uri.p) {
    std::string tmp(hm->uri.p);
    this->url += tmp.substr(0, hm->uri.len);
  }
  if (hm->method.p) {
    std::string tmp(hm->method.p);
    this->method += tmp.substr(0, hm->method.len);
  }
  if (hm->body.p) {
    std::string tmp(hm->body.p);
    this->body += tmp.substr(0, hm->body.len);
  }
  if (hm->query_string.p) {
    std::string tmp(hm->query_string.p);
    this->queryString += tmp.substr(0, hm->query_string.len);
  }

  for (size_t i = 0; hm->header_names[i].p; i++) {
    headerFields.push_back(
        HeaderField(hm->header_names[i].p, hm->header_values[i].p));
  }
}

Request::~Request() {}
