#include "SecondTime.h"

SecondTime::SecondTime(long seconds) {
  this->seconds = seconds;
}

long SecondTime::getMilliseconds() {
  return this->seconds * 1000;
}
