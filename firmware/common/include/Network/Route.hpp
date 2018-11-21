#pragma once

#include "Network/Request.hpp"
#include "Network/Response.hpp"

class Route {
 private:
  const char *path;
  const char *method;

 public:
  Route(const char *path, const char *method);
  virtual ~Route();

  bool match(const Request *request);
  virtual void handle(const Request *request, Response *response) = 0;
};
