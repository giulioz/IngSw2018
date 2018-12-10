#include "MockHardwareInterface.hpp"

#include <ctime>
#include <iostream>
using namespace std;

MockHardwareInterface::MockHardwareInterface() {
  cout << "Mock robot mode" << endl;
}

MockHardwareInterface::~MockHardwareInterface() {}

void MockHardwareInterface::left() { cout << "ROBOT: received Left" << endl; }

void MockHardwareInterface::right() { cout << "ROBOT: received Right" << endl; }

int MockHardwareInterface::getDistance() {
  auto time = std::time(0);

  if (time % 10 == 0) {
    cout << "ROBOT: simulated intrusion" << endl;
    return 100;
  } else {
    return 0;
  }
}

void MockHardwareInterface::poll() {}
