#include "Comm.hpp"

#include <iostream>

Comm::Comm(HardwareInterface *hardwareInterface, ImageCapturer *imageCapturer,
           UI *ui, DBConnector *dbConnector, const char *infoString)
    : server(),
      alarmEngine(hardwareInterface, imageCapturer, &db, &root),
      webApi(&server, hardwareInterface, &alarmEngine, ui, imageCapturer, &db,
             &root, infoString),
      discovery(&server, infoString),
      db(dbConnector),
      root() {
  this->hardwareInterface = hardwareInterface;
  this->imageCapturer = imageCapturer;
  this->ui = ui;
  this->dbConnector = dbConnector;

  try {
    this->db.fetch(root);
  } catch (const std::exception &ex) {
    std::cout << (ex.what()) << std::endl;
  }
}

Comm::~Comm() {}

void Comm::poll() {
  server.poll();
  alarmEngine.poll();
}
