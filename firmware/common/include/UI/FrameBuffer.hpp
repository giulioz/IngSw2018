#pragma once

template <typename T>
class FrameBuffer {
 public:
  virtual ~FrameBuffer() {}

  virtual T* getSurface() = 0;
  virtual int getWidth() = 0;
  virtual int getHeight() = 0;
};