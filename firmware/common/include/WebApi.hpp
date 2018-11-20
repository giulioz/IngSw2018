#pragma once

#include "HTTP/WebServer.hpp"
#include "Server.hpp"
#include "HardwareInterface.hpp"

class WebApi {
 private:
  WebServer webServer;
  HardwareInterface *hardwareInterface;

  void postPair(const Request *request, Response *response);

 public:
  WebApi(Server *server, HardwareInterface *hardwareInterface);
};
