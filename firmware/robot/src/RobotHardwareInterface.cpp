#include "RobotHardwareInterface.hpp"

#include <ctime>
#include <iostream>
using namespace std;

RobotHardwareInterface::RobotHardwareInterface() {
  cout << "Mock robot mode" << endl;
}

RobotHardwareInterface::~RobotHardwareInterface() {}

void RobotHardwareInterface::left() { cout << "ROBOT: received Left" << endl; }

void RobotHardwareInterface::right() {
  cout << "ROBOT: received Right" << endl;
}

int RobotHardwareInterface::getDistance() {
  auto time = std::time(0);

  if (time % 10 == 0) {
    cout << "ROBOT: simulated intrusion" << endl;
    return 100;
  } else {
    return 0;
  }
}

void RobotHardwareInterface::poll() {}
