#pragma once

#include "Server.hpp"
#include "Network/ServerUDP.hpp"

class Pairing {
 private:
  Server *server;
  ServerUDP serverUdp;

 public:
  Pairing(Server *server);
  ~Pairing();
};
