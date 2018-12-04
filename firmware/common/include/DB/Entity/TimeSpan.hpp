#pragma once

#include <string>

#include "DB/Entity/Time.hpp"

class TimeSpan {
 private:
  Time from;
  Time to;

 public:
  TimeSpan(const Time&, const Time&);
  TimeSpan(const TimeSpan&);

  Time& getFrom();
  Time& getTo();
  bool intersects(const TimeSpan&);
  std::string toString();
};
