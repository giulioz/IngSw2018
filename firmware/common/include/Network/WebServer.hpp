#pragma once

#include <mongoose.h>
#include <vector>
#include "Server.hpp"
#include "Network/NotFoundRoute.hpp"
#include "Network/Route.hpp"
#include "Network/Router.hpp"

class WebServer : public Router {
 private:
  Server *server;
  struct mg_connection *nc;

 public:
  WebServer(Server *server, const char *address);
  ~WebServer();
  void handler(struct mg_connection *nc, int ev, void *p);
};
