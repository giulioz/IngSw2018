#pragma once

#include <mongoose.h>
#include <Network/UDPData.hpp>
#include <Server.hpp>
#include <functional>

class ServerUDP {
 private:
  Server *server;
  struct mg_connection *connection;

  std::function<void(UDPData *data)> eventHandler;

 public:
  ServerUDP(Server *server, const char *address,
            std::function<void(UDPData *data)> eventHandler);
  ~ServerUDP();
  void handler(struct mg_connection *connection, int ev, void *p);
};
