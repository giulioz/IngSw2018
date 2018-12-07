#include "DB/Entity/Intrusion.hpp"

Intrusion::Intrusion(long id, long date, bool notified) {
  this->id = id;
  this->date = date;
  this->notified = notified;
}

Intrusion::Intrusion(const Intrusion &i) {
  this->id = (&i)->id;
  this->date = (&i)->date;
  this->notified = (&i)->notified;
}

std::string Intrusion::toString() {
  return std::string("{id:" + std::to_string(id) +
                     ", time:" + std::to_string(date) +
                     ", readt:" + (notified ? "true" : "false") + "}");
}
