#include "RobotHardwareInterface.hpp"

#include <ctime>
#include <iostream>
using namespace std;

#define MOTOR_PORT ev3dev::OUTPUT_A

RobotHardwareInterface::RobotHardwareInterface()
    : distanceSensor(), motor(MOTOR_PORT), sound() {
  motor.reset();
  motor.stop();
}

RobotHardwareInterface::~RobotHardwareInterface() {}

void RobotHardwareInterface::left() {
  cout << "Received left" << endl;

  motor.set_stop_action("brake");
  motor.set_speed_sp(60);
  motor.set_position_sp(10);
  motor.run_to_rel_pos();
}

void RobotHardwareInterface::right() {
  cout << "Received right" << endl;

  motor.set_stop_action("brake");
  motor.set_speed_sp(60);
  motor.set_position_sp(-10);
  motor.run_to_rel_pos();
}

int RobotHardwareInterface::getDistance() {
  return distanceSensor.distance_centimeters();
}

void RobotHardwareInterface::playAlarm() {
  cout << "Alarm!" << endl;
  sound.tone(440, 2000);
}

void RobotHardwareInterface::poll() {}
