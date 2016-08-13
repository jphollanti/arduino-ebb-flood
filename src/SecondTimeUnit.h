#pragma once
#ifndef SecondTimeUnit_h
#define SecondTimeUnit_h
#include "TimeUnit.h"

class SecondTimeUnit : public TimeUnit {
private:
  long seconds;
public:
  SecondTimeUnit(long seconds);
  long getMilliseconds();
};

#endif
