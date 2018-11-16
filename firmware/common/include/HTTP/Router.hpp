#pragma once

#include <vector>
#include "HTTP/NotFoundRoute.hpp"
#include "HTTP/Response.hpp"
#include "HTTP/Route.hpp"

class Router {
 private:
  const char *basePath;
  std::vector<Router *> childRouters;
  std::vector<Route *> routes;
  NotFoundRoute notFoundRoute;

 public:
  Router(const char *basePath);
  ~Router();

  void addRoute(Route *route);
  void addRouter(Router *router);
  bool match(const char *path);
  void handle(const char *path, const char *method, Response *response);
};
