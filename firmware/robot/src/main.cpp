#include "Comm.hpp"
#include "DB.hpp"
#include "RobotHardwareInterface.hpp"

int main() {
  DB db("test.db");
  RobotHardwareInterface robotHardwareInterface;

  Comm comm(&robotHardwareInterface);
  for (;;) {
    comm.poll();
    robotHardwareInterface.poll();
  }
}
