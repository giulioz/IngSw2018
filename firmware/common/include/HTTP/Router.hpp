#pragma once

#include <list>
#include "HTTP/AutoRoute.hpp"
#include "HTTP/NotFoundRoute.hpp"
#include "HTTP/Request.hpp"
#include "HTTP/Response.hpp"
#include "HTTP/Route.hpp"

class Router {
 private:
 public:
  const char *basePath;
  std::list<Router *> childRouters;
  std::list<Route *> routes;
  NotFoundRoute notFoundRoute;
  std::list<AutoRoute> autoRoutes;

  Router(const char *basePath);
  ~Router();

  bool match(const Request *request);
  void handle(const Request *request, Response *response);

  void addRoute(Route *route);
  void addRoute(const char *path, const char *method,
                void (*handler)(const Request *request, Response *response));
  void addRouter(Router *router);
};
