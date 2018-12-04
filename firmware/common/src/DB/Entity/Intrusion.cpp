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

long Intrusion::getId() { return this->id; }

long Intrusion::getDate() { return this->date; }

bool Intrusion::isNotified() { return this->notified; }

std::string Intrusion::toString() {
  return std::string("Intrusion(" + std::to_string(this->getId()) + ", " +
                     std::to_string(this->getDate()) + ", " +
                     (this->isNotified() ? "true" : "false") + ")");
}
