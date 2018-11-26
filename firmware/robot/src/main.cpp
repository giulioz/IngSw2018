#include "Comm.hpp"
#include "DB/DB.hpp"
#include "EV3Lcd.hpp"
#include "RobotHardwareInterface.hpp"

static const char *infoString = "Test robot";

int main() {
  DB db("test.db");
  RobotHardwareInterface robotHardwareInterface;
  ImageCapturer imageCapturer;
  EV3Lcd ev3Lcd;

  Comm comm(&robotHardwareInterface, &imageCapturer, &ev3Lcd, infoString);
  for (;;) {
    comm.poll();
    robotHardwareInterface.poll();
  }
}
