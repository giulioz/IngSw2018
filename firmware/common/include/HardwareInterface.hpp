#pragma once

class HardwareInterface {
 public:
  virtual ~HardwareInterface() {}

  virtual void left() = 0;
  virtual void right() = 0;
  virtual int getDistance() = 0;
  virtual void playAlarm() = 0;
};
