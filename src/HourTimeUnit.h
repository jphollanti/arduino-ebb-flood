#pragma once
#ifndef HourTimeUnit_h
#define HourTimeUnit_h
#include "TimeUnit.h"

class HourTimeUnit : public TimeUnit {
private:
  long hours;
public:
  HourTimeUnit(long hours);
  long getMilliseconds();
};

#endif
