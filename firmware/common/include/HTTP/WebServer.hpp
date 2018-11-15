#include <vector>
#include <mongoose.h>
#include "HTTP/Route.hpp"

#pragma once

class WebServer {
 private:
  struct mg_serve_http_opts httpServerOpts;
  struct mg_mgr mgr;
  struct mg_connection *nc;

  std::vector<Route> routes;

  void handler(struct mg_connection *nc, int ev, void *p);

 public:
  WebServer(const char *address);
  ~WebServer();
  void start();
  void get(const char *path);
};