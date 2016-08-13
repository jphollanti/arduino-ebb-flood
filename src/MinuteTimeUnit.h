#pragma once
#ifndef MinuteTimeUnit_h
#define MinuteTimeUnit_h
#include "TimeUnit.h"

class MinuteTimeUnit : public TimeUnit {
private:
  long minutes;
public:
  MinuteTimeUnit(long minutes);
  long getMilliseconds();
};

#endif
