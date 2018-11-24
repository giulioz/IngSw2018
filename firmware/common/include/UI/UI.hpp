#pragma once

class UI {
 private:
 public:
  virtual ~UI(){};

  virtual void drawPixel(int i, bool value) = 0;
  virtual int getWidth() = 0;
  virtual int getHeight() = 0;

  virtual void drawPixel(int x, int y, bool value);
  virtual void clear();
  virtual void drawText(int x, int y, const char* text);
};
