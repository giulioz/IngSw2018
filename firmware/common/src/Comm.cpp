#include "Comm.hpp"

Comm::Comm(HardwareInterface *hardwareInterface, ImageCapturer *imageCapturer,
           UI *ui, DBConnector *dbConnector, const char *infoString)
    : server(),
      alarmEngine(hardwareInterface, imageCapturer),
      webApi(&server, hardwareInterface, &alarmEngine, ui, imageCapturer, &db,
             infoString),
      discovery(&server, infoString),
      db(dbConnector) {
  this->hardwareInterface = hardwareInterface;
  this->imageCapturer = imageCapturer;
  this->ui = ui;
  this->dbConnector = dbConnector;
}

Comm::~Comm() {}

void Comm::poll() { server.poll(); }
