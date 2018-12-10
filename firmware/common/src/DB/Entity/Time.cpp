#include "DB/Entity/Time.hpp"

#include <exception>
#include <stdexcept>

Time::Time(long hour, long minute) {
  this->hour = hour;
  this->minute = minute;
  if (this->hour < 0 || this->hour > 23 || this->minute < 0 ||
      this->minute > 59) {
    throw std::invalid_argument("time");
  }
}

Time::Time(const Time& t) {
  this->hour = (&t)->hour;
  this->minute = (&t)->minute;
}

long Time::getHour() { return this->hour; }

long Time::getMinute() { return this->minute; }

long Time::compare(const Time& t) {
  if (this->hour < (&t)->hour ||
      (this->hour == (&t)->hour && this->minute < (&t)->minute)) {
    return -1;
  } else if (this->hour == (&t)->hour && this->minute == (&t)->minute) {
    return 0;
  }
  return 1;
}

bool Time::equals(const Time& t) { return (this->compare(t) == 0); }

std::string Time::toString() {
  return std::string("Time(" + std::to_string(this->getHour()) + ", " +
                     std::to_string(this->getMinute()) + ")");
}
