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

int _main() {
  bool running = true;

  MockHardwareInterface mockHardwareInterface;
  ImageCapturer imageCapturer;
  SDLFrameBuffer sdlFrameBuffer;
  DBConnector dbC("test.db");
  Comm comm(&mockHardwareInterface, &imageCapturer, &sdlFrameBuffer, &dbC,
            infoString);

  while (running) {
    mockHardwareInterface.poll();
    sdlFrameBuffer.poll(&running);
    comm.poll();
  }

  return 0;
}

/* STUB */
#ifdef WIN32
#include <windows.h>
int CALLBACK WinMain(HINSTANCE a, HINSTANCE b, LPSTR c, int d) {
  return _main();
}
#else
int main(int argc, char **argv) { return _main(); }
#endif
