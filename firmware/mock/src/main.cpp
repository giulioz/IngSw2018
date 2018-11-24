#include <SDL.h>
#include <string.h>
#include "Comm.hpp"
#include "DB/DB.hpp"
#include "MockHardwareInterface.hpp"
#include "SDLFrameBuffer.hpp"
#include "Webcam/ImageCapturer.hpp"

static const char *infoString = "WatchDoge\nMOCK server dev version";

int main() {
  bool running = true;

  DB db("test.db");

  SDLFrameBuffer sdlFrameBuffer;
  MockHardwareInterface mockHardwareInterface;
  ImageCapturer imageCapturer;
  Comm comm(&mockHardwareInterface, &imageCapturer, infoString);

  while (running) {
    mockHardwareInterface.poll();
    sdlFrameBuffer.poll(&running);
    comm.poll();

    SDL_Delay(10);
  }
}
