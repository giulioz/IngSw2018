#include "Webcam/ImageCapturer.hpp"

ImageCapturer::ImageCapturer() : camera(0) {}

std::vector<uchar> ImageCapturer::capture() {
  std::vector<uchar> buffer;
  std::vector<int> param(2);
  param[0] = cv::IMWRITE_JPEG_QUALITY;
  param[1] = 80;
  Mat frame = this->camera.read(frame);
  cv::imencode(".jpg", frame, buffer, param);
  return buffer;
}
