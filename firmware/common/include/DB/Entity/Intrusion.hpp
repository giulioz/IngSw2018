#pragma once

#include <string>

class Intrusion {
 private:

 public:
  Intrusion(long, long, bool);
  Intrusion(const Intrusion &);

  long id;
  long date;
  bool notified;
  
  std::string toString();
};
