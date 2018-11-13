#include <mongoose.h>

#pragma once

class WebServer {
 private:
  struct mg_serve_http_opts httpServerOpts;
  struct mg_mgr mgr;
  struct mg_connection *nc;

 public:
  WebServer(const char *address);
  ~WebServer();
  void start();
  void handler(struct mg_connection *nc, int ev, void *p);
};
