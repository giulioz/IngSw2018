#pragma once

#include "HTTP/Request.hpp"
#include "HTTP/Response.hpp"
#include "HTTP/Route.hpp"

class AutoRoute : public Route {
 private:
  void (*handler)(const Request *request, Response *response);

 public:
  AutoRoute(const char *path, const char *method,
            void (*handler)(const Request *request, Response *response));
  void handle(const Request *request, Response *response) override;
};
