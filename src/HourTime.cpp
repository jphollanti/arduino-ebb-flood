#include "HourTime.h"

HourTime::HourTime(long hours) {
  this->hours = hours;
}

long HourTime::getMilliseconds() {
  return this->hours * 3600000;
}
