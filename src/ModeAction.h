#pragma once
#ifndef ModeAction_h
#define ModeAction_h
#include "WaterPump.h"

class ModeAction {
public:
  virtual void setMode(WaterPump *waterPump) = 0;
};

#endif
