#pragma once

#include "HTTP/WebServer.hpp"
#include "Server.hpp"
#include "HardwareInterface.hpp"

class WebApi {
 private:
  WebServer webServer;
  HardwareInterface *hardwareInterface;

 public:
  WebApi(Server *server, HardwareInterface *hardwareInterface);
};
