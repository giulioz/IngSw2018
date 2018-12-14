#include <SDL.h>
#include <iostream>
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
<<<<<<< HEAD
  try {
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
  } catch (const std::exception &ex) {
    std::cout << ex.what() << std::endl;
=======
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
>>>>>>> 3c14791c31c2d68b3cf537331eb0e20425c46b16
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
