#pragma once

class Intrusion {
 private:
  long id;
  long date;
  bool notified;

 public:
  Intrusion(long, long, bool);
  Intrusion(const Intrusion&);

  long getId() const;
  long getDate() const;
  bool isNotified() const;
};
