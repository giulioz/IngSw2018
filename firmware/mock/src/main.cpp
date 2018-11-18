#include "Comm.hpp"
#include "DB/DB.hpp"

int main() {
  DB db("test.db");

  Comm comm;
  comm.start();
}
