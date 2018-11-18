#pragma once

#include "HTTP/WebServer.hpp"
#include "Server.hpp" 
#include "UDP/ServerUDP.hpp"
#include "UDP/UDPData.hpp"

class TestRoute : public Route {
 public:
  TestRoute();
  void handle(const Request *request, Response *response) override;
};

class EchoRoute : public Route {
 public:
  EchoRoute();
  void handle(const Request *request, Response *response) override;
};

class Comm {
 private:
 public:
  Server server;
  WebServer webServer;
  ServerUDP serverUdp;

  TestRoute testRoute;
  EchoRoute echoRoute;

  Comm();
  ~Comm();

  void poll();
  void start();
};
