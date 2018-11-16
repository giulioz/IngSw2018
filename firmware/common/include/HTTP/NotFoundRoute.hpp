#pragma once

#include "HTTP/Response.hpp"
#include "HTTP/Route.hpp"

class NotFoundRoute : public Route {
 public:
  NotFoundRoute();

  void handle(Response *res);
};
