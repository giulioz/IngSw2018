#pragma once

#include <string>

class Intrusion {
 private:
  long id;
  long date;
  bool notified;

 public:
  Intrusion(long, long, bool);
  Intrusion(const Intrusion &);

  long getId();
  long getDate();
  bool isNotified();
  std::string toString();
};
