#include "MockHardwareInterface.hpp"

#include <iostream>
using namespace std;

MockHardwareInterface::MockHardwareInterface() {
  cout << "Mock robot mode" << endl;
}

MockHardwareInterface::~MockHardwareInterface() {}

void MockHardwareInterface::left() { cout << "ROBOT: received Left" << endl; }

void MockHardwareInterface::right() { cout << "ROBOT: received Right" << endl; }

int MockHardwareInterface::getDistance() {
  cout << "ROBOT: sent mock distance" << endl;
  return 0;
}

void MockHardwareInterface::poll() {}
