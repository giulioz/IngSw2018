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
