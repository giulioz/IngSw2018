#pragma once

#include "Network/WebServer.hpp"
#include "HardwareInterface.hpp"
#include "Server.hpp"

class WebApi {
 private:
  WebServer webServer;
  HardwareInterface *hardwareInterface;
  const char *infoString;

  void loadRoutes();

  // Data
  void getIntrusions(const Request *request, Response *response);
  void getIntrusionsUnread(const Request *request, Response *response);
  void getIntrusionsTime(const Request *request, Response *response);
  void getIntrusionShoot(const Request *request, Response *response);

  // Hardware
  void getShoot(const Request *request, Response *response);
  void postLeft(const Request *request, Response *response);
  void postRight(const Request *request, Response *response);
  void getDistance(const Request *request, Response *response);

  // Authentication
  void postPair(const Request *request, Response *response);
  void deletePair(const Request *request, Response *response);

  // Misc
  void getInfo(const Request *request, Response *response);

 public:
  WebApi(Server *server, HardwareInterface *hardwareInterface, const char *infoString);
};
