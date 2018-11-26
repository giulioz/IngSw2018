#pragma once
#include "UI/UI.hpp"
#include "ev3dev.h"

class EV3Lcd : public UI {
 private:
  ev3dev::lcd lcd;

 public:
  EV3Lcd();
  ~EV3Lcd();

  virtual void drawPixel(int i, bool value) override;
  virtual void drawPixel(int x, int y, bool value) override;
  virtual void clear() override;
  virtual int getWidth() override;
  virtual int getHeight() override;
};
