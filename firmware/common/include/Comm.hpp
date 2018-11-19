#pragma once

#include "HTTP/WebServer.hpp"
#include "Server.hpp" 
#include "UDP/ServerUDP.hpp"
#include "UDP/UDPData.hpp"

class Comm {
 private:
 public:
  Server server;
  WebServer webServer;
  ServerUDP serverUdp;

  Comm();
  ~Comm();

  void poll();
  void start();
};
