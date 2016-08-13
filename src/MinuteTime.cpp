#include "MinuteTime.h"

MinuteTime::MinuteTime(long minutes) {
  this->minutes = minutes;
}

long MinuteTime::getMilliseconds() {
  return this->minutes * 60000;
}
