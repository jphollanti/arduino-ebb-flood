#pragma once
#ifndef SecondTime_h
#define SecondTime_h
#include "Time.h"

class SecondTime : public Time {
private:
  long seconds;
public:
  SecondTime(long seconds);
  long getMilliseconds();
};

#endif
