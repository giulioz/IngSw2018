#pragma once

#include <vector>
#include <mongoose.h>
#include "HTTP/Route.hpp"
#include "HTTP/NotFoundRoute.hpp"

class WebServer {
 private:
  struct mg_mgr mgr;
  struct mg_connection *nc;

  std::vector<Route*> routes;
  NotFoundRoute notFoundRoute;


 public:
  WebServer(const char *address);
  ~WebServer();
  void start();
  void handler(struct mg_connection *nc, int ev, void *p);

  void addRoute(Route *route);
};
