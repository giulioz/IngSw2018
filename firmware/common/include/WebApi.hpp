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

  // Alarm
  void getAlarmStatus(const Request *request, Response *response);
  void getAutoConf(const Request *request, Response *response);
  void postAlarmOn(const Request *request, Response *response);
  void postAlarmOff(const Request *request, Response *response);
  void postAutoToggle(const Request *request, Response *response);
  void postAutoConf(const Request *request, Response *response);

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
  void getPair(const Request *request, Response *response);
  void postPair(const Request *request, Response *response);

  // Misc
  void getInfo(const Request *request, Response *response);
  void getTest(const Request *request, Response *response);

 public:
  WebApi(Server *server, HardwareInterface *hardwareInterface,
         ImageCapturer *imageCapturer, const char *infoString);
};
