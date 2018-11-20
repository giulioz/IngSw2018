#include "Comm.hpp"
#include "DB/DB.hpp"
#include "MockHardwareInterface.hpp"

int main() {
  DB db("test.db");

  MockHardwareInterface mockHardwareInterface;
  Comm comm(&mockHardwareInterface);
  for (;;) {
    comm.poll();
    mockHardwareInterface.poll();
  }
}
