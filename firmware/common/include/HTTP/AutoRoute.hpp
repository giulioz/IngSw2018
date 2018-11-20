#pragma once

#include "HTTP/Request.hpp"
#include "HTTP/Response.hpp"
#include "HTTP/Route.hpp"

#include <functional>

class AutoRoute : public Route {
 private:
  std::function<void(const Request *request, Response *response)> handler;

 public:
  AutoRoute(const char *path, const char *method,
            std::function<void(const Request *request, Response *response)>);
  void handle(const Request *request, Response *response) override;
};
