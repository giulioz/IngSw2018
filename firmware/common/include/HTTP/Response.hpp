#include <mongoose.h>

#pragma once

class Response {
 private:
 public:
  struct mg_connection *connection;
  Response(struct mg_connection *connection);
  virtual ~Response();
};
