#include "Comm.hpp"
#include "DB/DB.hpp"
#include "MockHardwareInterface.hpp"
#include "Webcam/ImageCapturer.hpp"

static const char *infoString = "WatchDoge\nMOCK server dev version";

int main() {
  DB db("test.db");

  MockHardwareInterface mockHardwareInterface;
  ImageCapturer imageCapturer;
  Comm comm(&mockHardwareInterface, &imageCapturer, infoString);
  for (;;) {
    comm.poll();
    mockHardwareInterface.poll();
  }
}
