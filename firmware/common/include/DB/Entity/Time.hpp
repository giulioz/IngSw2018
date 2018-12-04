#pragma once

#include <string>

class Time {
 private:
  long hour;
  long minute;

 public:
  Time(long, long);
  Time(const Time&);

  long getHour();
  long getMinute();
  long compare(const Time&);
  bool equals(const Time&);
  std::string toString();
};
