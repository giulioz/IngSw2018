#include "HTTP/Response.hpp"

Response::Response(struct mg_connection *connection) {
  this->connection = connection;
}

Response::~Response() {}