#pragma once

#include <vector>
#include "HTTP/NotFoundRoute.hpp"
#include "HTTP/Request.hpp"
#include "HTTP/Response.hpp"
#include "HTTP/Route.hpp"

class Router {
 private:
 public:
  const char *basePath;
  std::vector<Router *> childRouters;
  std::vector<Route *> routes;
  NotFoundRoute notFoundRoute;

  Router(const char *basePath);
  ~Router();

  void addRoute(Route *route);
  void addRouter(Router *router);
  bool match(const Request *request);
  void handle(const Request *request, Response *response);
};
