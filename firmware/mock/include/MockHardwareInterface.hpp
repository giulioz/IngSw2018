#pragma once

#include "HardwareInterface.hpp"

class MockHardwareInterface : public HardwareInterface {
 public:
  MockHardwareInterface();
  virtual ~MockHardwareInterface() override;

  virtual void left() override;
  virtual void right() override;
  virtual int getDistance() override;
  virtual void playAlarm() override;

  void poll();
};
