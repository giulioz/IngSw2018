#pragma once

#include <mongoose.h>
#include <Server.hpp>
#include <UDP/UDPData.hpp>

class ServerUDP {
 private:
  Server *server;
  struct mg_connection *connection;

  void (*eventHandler)(UDPData *data);

 public:
  ServerUDP(Server *server, const char *address);
  ~ServerUDP();
  void handler(struct mg_connection *connection, int ev, void *p);
  void setEventHandler(void (*eventHandler)(UDPData *data));
};
