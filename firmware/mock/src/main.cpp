#include <SDL.h>
#include <string.h>
#include "Comm.hpp"
#include "DB/DB.hpp"
#include "MockHardwareInterface.hpp"
#include "SDLFrameBuffer.hpp"
#include "Webcam/ImageCapturer.hpp"

static const char *infoString = "MOCK server dev version";

int main() {
  bool running = true;

  DB db("test.db");

  SDLFrameBuffer sdlFrameBuffer;
  MockHardwareInterface mockHardwareInterface;
  ImageCapturer imageCapturer;
  Comm comm(&mockHardwareInterface, &imageCapturer, &sdlFrameBuffer,
            infoString);

  sdlFrameBuffer.clear();
  sdlFrameBuffer.UI::drawPixel(10, 10, true);
  sdlFrameBuffer.UI::drawPixel(15, 10, true);
  sdlFrameBuffer.UI::drawPixel(12, 20, true);
  sdlFrameBuffer.UI::drawPixel(10, 13, true);

  while (running) {
    mockHardwareInterface.poll();
    sdlFrameBuffer.poll(&running);
    comm.poll();

    SDL_Delay(10);
  }
}
