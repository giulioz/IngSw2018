#include "HTTP/Router.hpp"

Router::Router(const char *basePath) { this->basePath = basePath; }

Router::~Router() {}

void Router::addRoute(Route *route) { this->routes.push_back(route); }

void Router::addRouter(Router *router) { this->childRouters.push_back(router); }

static bool _match(const char *str, const char *toMatch) {
  if (!*str && !*toMatch) {
    return true;
  } else if (!*str && *toMatch) {
    return false;
  } else if (*str && !*toMatch) {
    return true;
  } else if (*str == *toMatch) {
    return _match(str + 1, toMatch + 1);
  }

  return false;
}

bool Router::match(const char *path) { return _match(path, this->basePath); }

void Router::handle(const char *path, const char *method, Response *response) {
  for (auto route : routes) {
    if (route->match(path, method)) {
      route->handle(response);
      return;
    }
  }

  for (auto router : childRouters) {
    if (router->match(path)) {
      router->handle(path, method, response);
      return;
    }
  }

  this->notFoundRoute.handle(response);
}
