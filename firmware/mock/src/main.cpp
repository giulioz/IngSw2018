<<<<<<< HEAD
#include "Comm.hpp"
#include "DB/DB.hpp"

int main() {
  DB db("test.db");

  Comm comm;
  comm.start();
}
=======
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
>>>>>>> 9b9ccae2315b8d9384a57a0d2b49d00c0e52c2fb
