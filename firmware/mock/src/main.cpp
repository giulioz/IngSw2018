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
  DBConnector dbC("test.db");
  DB db(&dbC);
  Root root = db.fetch();
  /*
    root.setActive(true);
    root.getAuthKeys().insert(std::pair<std::string, std::string>(
        std::string("hello"), std::string("world")));
    root.getAutoModeConf()[WeekDay::MONDAY].push_back(
        TimeSpan(Time(15, 0), Time(16, 29)));
    root.getAutoModeConf()[WeekDay::SATURDAY].push_back(
        TimeSpan(Time(20, 0), Time(23, 59)));
    root.getIntrusions().push_back(Intrusion(1, 0xfeed, true));
    db.store(root);
  */

  bool running = true;

  SDLFrameBuffer sdlFrameBuffer;
  MockHardwareInterface mockHardwareInterface;
  ImageCapturer imageCapturer("/dev/video0");
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
