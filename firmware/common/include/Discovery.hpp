#pragma once

#include "Network/ServerUDP.hpp"
#include "Network/UDPData.hpp"
#include "Server.hpp"

class Discovery {
 private:
  Server *server;
  ServerUDP serverUdp;

 public:
  Discovery(Server *server, const char *info);
  ~Discovery();
};
