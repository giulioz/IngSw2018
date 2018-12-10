#include <SDL.h>
#include <string>

#include "Comm.hpp"
#include "MockHardwareInterface.hpp"
#include "SDLFrameBuffer.hpp"
#include "Webcam/ImageCapturer.hpp"

#include "DB/DB.hpp"
#include "DB/DBConnector.hpp"
#include "DB/Entity/Time.hpp"
#include "DB/Entity/TimeSpan.hpp"
#include "DB/Entity/WeekDay.hpp"

static const char *infoString = "Doge Server (Mock)";

int main() {
  bool running = true;

  SDLFrameBuffer sdlFrameBuffer;
  MockHardwareInterface mockHardwareInterface;
  ImageCapturer imageCapturer;
  DBConnector dbC("test.db");
  Comm comm(&mockHardwareInterface, &imageCapturer, &sdlFrameBuffer, &dbC,
            infoString);

  while (running) {
    mockHardwareInterface.poll();
    sdlFrameBuffer.poll(&running);
    comm.poll();
  }
}
