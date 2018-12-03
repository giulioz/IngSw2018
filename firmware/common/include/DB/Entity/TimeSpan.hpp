#pragma once

#include "DB/Entity/Time.hpp"

class TimeSpan {
 private:
  Time from;
  Time to;

 public:
  TimeSpan(const Time&, const Time&);
  TimeSpan(const TimeSpan&);

  Time getFrom() const;
  Time getTo() const;
  bool intersects(const TimeSpan&) const;
};
