#include "RobotHardwareInterface.hpp"

#include <ctime>
#include <iostream>
using namespace std;

#define MOTOR_PORT ev3dev::OUTPUT_A

RobotHardwareInterface::RobotHardwareInterface()
    : distanceSensor(), motor(MOTOR_PORT), sound() {
  motor.stop();
  motor.reset();
}

RobotHardwareInterface::~RobotHardwareInterface() {}

void RobotHardwareInterface::left() {
  motor.set_duty_cycle_sp(20);
  motor.set_position_sp(10);
  motor.run_to_rel_pos();
}

void RobotHardwareInterface::right() {
  motor.set_duty_cycle_sp(20);
  motor.set_position_sp(-10);
  motor.run_to_rel_pos();
}

int RobotHardwareInterface::getDistance() {
  return distanceSensor.distance_centimeters();
}

void RobotHardwareInterface::playAlarm() {
  sound.tone(440, 2000);
}

void RobotHardwareInterface::poll() {}
