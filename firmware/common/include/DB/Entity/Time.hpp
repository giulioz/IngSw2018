#pragma once

class Time {
 private:
  long hour;
  long minute;

 public:
  Time(long, long);
  Time(const Time&);

  long getHour() const;
  long getMinute() const;
  long compare(const Time&) const;
  bool equals(const Time&) const;
};
