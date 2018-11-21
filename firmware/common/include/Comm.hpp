#pragma once

#include "HTTP/WebServer.hpp"
#include "Server.hpp"
#include "UDP/ServerUDP.hpp"
#include "UDP/UDPData.hpp"
#include "Pairing.hpp"

class Comm {
 private:
 public:
  Server server;
  WebServer webServer;
  Pairing pairing;

  Comm();
  ~Comm();

  void poll();
  void start();
};
