#pragma once

#include "HTTP/Response.hpp"

class Route {
 private:
  const char *path;
  const char *method;

 public:
  Route(const char *path, const char *method);
  virtual ~Route();

  bool match(const char *path, const char *method);
  virtual void handle(Response* response) = 0;
};
