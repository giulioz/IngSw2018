#include "Webcam/ImageCapturer.hpp"

#include <iostream>

#define WIDTH 320
#define HEIGHT 240

ImageCapturer::ImageCapturer() : camera(0) {
  if (!camera.isOpened()) {
    std::cout << "Error opening video stream." << std::endl;
  }
  this->camera.set(cv::CAP_PROP_FRAME_WIDTH, WIDTH);
  this->camera.set(cv::CAP_PROP_FRAME_HEIGHT, HEIGHT);

  cv::Mat frame;
  this->camera.read(frame);
}

ImageCapturer::ImageCapturer(const char* videoId) : camera(videoId) {
  if (!camera.isOpened()) {
    std::cout << "Error opening video stream." << std::endl;
  }
  this->camera.set(cv::CAP_PROP_FRAME_WIDTH, WIDTH);
  this->camera.set(cv::CAP_PROP_FRAME_HEIGHT, HEIGHT);

  cv::Mat frame;
  this->camera.read(frame);
}

ImageCapturer::~ImageCapturer() { camera.release(); }

std::vector<uchar> ImageCapturer::captureJpeg() {
  std::vector<uchar> buffer;
  std::vector<int> param(2);
  param[0] = cv::IMWRITE_JPEG_QUALITY;
  param[1] = 80;
  cv::Mat frame;
  // camera >> frame;
  while (!this->camera.read(frame))
    ;

  cv::imencode(".jpg", frame, buffer, param);
  return buffer;
}
