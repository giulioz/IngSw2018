#include "Webcam/ImageCapturer.hpp"

ImageCapturer::ImageCapturer() : camera(0) {}

Mat ImageCapturer::capture() { return this->camera.read(frame); }
