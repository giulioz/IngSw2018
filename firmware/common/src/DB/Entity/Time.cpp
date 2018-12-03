#include "DB/Entity/Time.hpp"

Time::Time(long hour, long minute) {
  this->hour = hour;
  this->minute = minute;
  if (this->hour < 0 || this->hour > 23 || this->minute < 0 ||
      this->minute > 59) {
    throw "Invalid argument.";
  }
}

Time::Time(const Time& t) {
  this->hour = (&t)->hour;
  this->minute = (&t)->minute;
}

long Time::getHour() const { return this->hour; }

long Time::getMinute() const { return this->minute; }

long Time::compare(const Time& t) const {
  if (this->hour < (&t)->hour ||
      (this->hour == (&t)->hour && this->minute < (&t)->minute)) {
    return -1;
  } else if (this->hour == (&t)->hour && this->minute == (&t)->minute) {
    return 0;
  }
  return 1;
}

bool Time::equals(const Time& t) const { return (this->compare(t) == 0); }
