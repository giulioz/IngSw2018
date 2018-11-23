#pragma once

#include "Network/ServerUDP.hpp"
#include "Network/UDPData.hpp"
#include "Server.hpp"

class Pairing {
 private:
  Server *server;
  ServerUDP serverUdp;

 public:
  Pairing(Server *server, const char *info);
  ~Pairing();
};
