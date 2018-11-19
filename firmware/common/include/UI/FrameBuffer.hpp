#pragma once

template <typename T>
class FrameBuffer {
 public:
  virtual ~FrameBuffer() = 0;

  virtual T* getSurface() = 0;
  virtual int getWidth() = 0;
  virtual int getHeight() = 0;
  virtual void switchBuffers() = 0;
};