#include "Comm.hpp"
#include "DB/DB.hpp"
#include "EV3Lcd.hpp"
#include "RobotHardwareInterface.hpp"

static const char *infoString = "Test robot";

int main() {
  DBConnector dbC("test.db");
  DB db(&dbC);
  Root root;
  db.fetch(root);

  RobotHardwareInterface robotHardwareInterface;
  ImageCapturer imageCapturer("/dev/video0");
  EV3Lcd ev3Lcd;

  Comm comm(&robotHardwareInterface, &imageCapturer, &ev3Lcd, infoString);
  for (;;) {
    comm.poll();
    robotHardwareInterface.poll();
  }
}
