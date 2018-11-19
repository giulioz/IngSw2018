#pragma once

#include <mongoose.h>

class Server {
 private:
 public:
  struct mg_mgr mgr;
  Server();
  ~Server();

  mg_connection *bind(const char *address,
                      void (*handler)(struct mg_connection *nc, int ev,
                                      void *p),
                      void *ref);

  void poll();
};
