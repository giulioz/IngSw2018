#include "Comm.hpp"
#include "DB/DB.hpp"
#include "EV3Lcd.hpp"
#include "RobotHardwareInterface.hpp"

static const char *infoString = "EV3";

int main() {
  RobotHardwareInterface robotHardwareInterface;
  ImageCapturer imageCapturer("/dev/video0");
  DBConnector dbC("test.db");
  EV3Lcd ev3Lcd;

  Comm comm(&robotHardwareInterface, &imageCapturer, &ev3Lcd, &dbC, infoString);
  for (;;) {
    comm.poll();
    robotHardwareInterface.poll();
  }
}
