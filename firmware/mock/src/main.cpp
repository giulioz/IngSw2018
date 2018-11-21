#include "Comm.hpp"
#include "DB/DB.hpp"
#include "MockHardwareInterface.hpp"

static const char *infoString = "WatchDoge\nMOCK server dev version";

int main() {
  DB db("test.db");

  MockHardwareInterface mockHardwareInterface;
  Comm comm(&mockHardwareInterface, infoString);
  for (;;) {
    comm.poll();
    mockHardwareInterface.poll();
  }
}
