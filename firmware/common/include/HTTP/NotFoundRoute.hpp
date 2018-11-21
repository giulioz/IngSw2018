#pragma once

#include "HTTP/Route.hpp"

class NotFoundRoute : public Route {
 public:
  NotFoundRoute();
  void handle(const Request *request, Response *response) override;
};
