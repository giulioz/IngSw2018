#include "Webcam/MotionDetector.hpp"

using namespace std;
using namespace cv;

MotionDetector::MotionDetector(void (*callback)(void)) : camera(0) {
  this->callback = callback;
  this->first = true;
}

void MotionDetector::poll() {
  Mat frame, gray, frameDelta, thresh;
  vector<vector<Point> > cnts;

  if (this->first) {
    // set the video size to 512x288 to process faster
    this->camera.set(3, 512);
    this->camera.set(4, 288);

    sleep(3);
    this->camera.read(frame);

    // convert to grayscale and set the first frame
    cvtColor(frame, this->firstFrame, COLOR_BGR2GRAY);
    GaussianBlur(this->firstFrame, this->firstFrame, Size(21, 21), 0);

    this->first = false;
  }

  this->camera.read(frame);

  // convert to grayscale
  cvtColor(frame, gray, COLOR_BGR2GRAY);
  GaussianBlur(gray, gray, Size(21, 21), 0);

  // compute difference between first frame and current frame
  absdiff(this->firstFrame, gray, frameDelta);
  threshold(frameDelta, thresh, 25, 255, THRESH_BINARY);

  dilate(thresh, thresh, Mat(), Point(-1, -1), 2);
  findContours(thresh, cnts, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

  for (int i = 0; i < cnts.size(); i++) {
    if (contourArea(cnts[i]) < 500) {
      continue;
    }
    this->callback();
  }
}
