#pragma once

#include "Network/Request.hpp"
#include "Network/Response.hpp"
#include "Network/Route.hpp"

#include <functional>

class AutoRoute : public Route {
 private:
  std::function<void(const Request *request, Response *response)> handler;

 public:
  AutoRoute(const char *path, const char *method,
            std::function<void(const Request *request, Response *response)> handler);
  void handle(const Request *request, Response *response) override;
};
