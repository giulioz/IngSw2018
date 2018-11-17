#pragma once

#include <mongoose.h>
#include <vector>
#include "Server.hpp"
#include "HTTP/NotFoundRoute.hpp"
#include "HTTP/Route.hpp"
#include "HTTP/Router.hpp"

class WebServer : public Router {
 private:
  Server *server;
  struct mg_connection *nc;

 public:
  WebServer(Server *server, const char *address);
  ~WebServer();
  void handler(struct mg_connection *nc, int ev, void *p);
};
