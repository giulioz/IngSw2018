#pragma once

#include <mongoose.h>
#include <vector>
#include "HTTP/NotFoundRoute.hpp"
#include "HTTP/Route.hpp"
#include "HTTP/Router.hpp"

class WebServer : public Router {
 private:
  struct mg_mgr mgr;
  struct mg_connection *nc;

 public:
  WebServer(const char *address);
  ~WebServer();
  void start();
  void handler(struct mg_connection *nc, int ev, void *p);
};
