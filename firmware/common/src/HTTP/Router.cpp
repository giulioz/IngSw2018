#include "HTTP/Router.hpp"

Router::Router(const char *basePath) {
  this->basePath = basePath;
}

Router::~Router() {}

void Router::addRoute(Route *route) { routes.push_back(route); }

void Router::addRouter(Router *router) { childRouters.push_back(router); }

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

bool Router::match(const Request *request) {
  return _match(request->url.c_str(), this->basePath);
}

void Router::handle(const Request *request, Response *response) {
  for (auto route : routes) {
    if (route->match(request)) {
      route->handle(request, response);
      return;
    }
  }

  for (auto router : childRouters) {
    if (router->match(request)) {
      router->handle(request, response);
      return;
    }
  }

  this->notFoundRoute.handle(request, response);
}
