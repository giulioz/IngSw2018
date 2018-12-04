#pragma once

#include "HardwareInterface.hpp"
#include "Network/WebServer.hpp"
#include "Server.hpp"
#include "Webcam/ImageCapturer.hpp"

class WebApi {
 private:
  WebServer webServer;
  HardwareInterface *hardwareInterface;
  ImageCapturer *imageCapturer;
  const char *infoString;

  void loadRoutes();

  // Allarm
  void getAllarmState(const Request *request, Response *response);
  void getAllarmProgram(const Request *request, Response *response);
  void postAllarmOn(const Request *request, Response *response);
  void postAllarmOff(const Request *request, Response *response);
  void postAllarmAuto(const Request *request, Response *response);
  void postAllarmProgram(const Request *request, Response *response);

  // Data
  void getIntrusions(const Request *request, Response *response);
  void getIntrusionsUnread(const Request *request, Response *response);
  void getIntrusionsTime(const Request *request, Response *response);
  void getIntrusionShoot(const Request *request, Response *response);

  // Hardware
  void getShoot(const Request *request, Response *response);
  void postLeft(const Request *request, Response *response);
  void postRight(const Request *request, Response *response);

  // Authentication
  void postPair(const Request *request, Response *response);

  // Misc
  void getInfo(const Request *request, Response *response);
  void getTest(const Request *request, Response *response);

 public:
  WebApi(Server *server, HardwareInterface *hardwareInterface,
         ImageCapturer *imageCapturer, const char *infoString);
};
