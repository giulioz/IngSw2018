#pragma once

#include "HTTP/WebServer.hpp"
#include "Server.hpp"

class WebApi {
 private:
  WebServer webServer;

  void postPair(const Request *request, Response *response);

 public:
  WebApi(Server *server);
};
