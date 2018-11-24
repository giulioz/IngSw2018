
#pragma once

#include "HardwareInterface.hpp"
#include "Pairing.hpp"
#include "Server.hpp"
#include "UI/UI.hpp"
#include "WebApi.hpp"
#include "Webcam/ImageCapturer.hpp"

class Comm {
 private:
  HardwareInterface *hardwareInterface;
  ImageCapturer *imageCapturer;
  UI *ui;

 public:
  Server server;
  WebApi webApi;
  Pairing pairing;

  Comm(HardwareInterface *hardwareInterface, ImageCapturer *imageCapturer,
       UI *ui, const char *infoString);
  ~Comm();

  void poll();
};
