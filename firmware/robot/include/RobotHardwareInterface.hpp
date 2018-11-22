#pragma once

#include "HardwareInterface.hpp"

class RobotHardwareInterface : public HardwareInterface {
 public:
  RobotHardwareInterface();
  virtual ~RobotHardwareInterface() override;

  virtual void left() override;
  virtual void right() override;
  virtual int getDistance() override;

  void poll();
};