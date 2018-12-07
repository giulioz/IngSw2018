
#pragma once

#include "HardwareInterface.hpp"
#include "Discovery.hpp"
#include "Server.hpp"
#include "UI/UI.hpp"
#include "WebApi.hpp"
#include "Webcam/ImageCapturer.hpp"
#include "DB/DBConnector.hpp"
#include "DB/DB.hpp"
#include "DB/Entity/Root.hpp"

class Comm {
 private:
  HardwareInterface *hardwareInterface;
  ImageCapturer *imageCapturer;
  UI *ui;
  DBConnector *dbConnector;

 public:
  Server server;
  WebApi webApi;
  Discovery discovery;
  DB db;
  Root root;
  AlarmEngine alarmEngine;

  Comm(HardwareInterface *hardwareInterface, ImageCapturer *imageCapturer,
       UI *ui, DBConnector *dbConnector, const char *infoString);
  ~Comm();

  void poll();
};
