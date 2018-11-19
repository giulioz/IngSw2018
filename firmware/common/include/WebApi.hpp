#pragma once

#include "HTTP/WebServer.hpp"
#include "Server.hpp"

class WebApi {
 private:
  WebServer webServer;

 public:
  WebApi(Server *server);
};
