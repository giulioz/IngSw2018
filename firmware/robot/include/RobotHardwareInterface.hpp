#pragma once

#include "HardwareInterface.hpp"
#include "ev3dev.h"

class RobotHardwareInterface : public HardwareInterface {
 private:
  ev3dev::ultrasonic_sensor distanceSensor;
  ev3dev::motor motor;
  ev3dev::sound sound;

 public:
  RobotHardwareInterface();
  virtual ~RobotHardwareInterface() override;

  virtual void left() override;
  virtual void right() override;
  virtual int getDistance() override;
  virtual void playAlarm() override;

  void poll();
};
