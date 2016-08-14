#pragma once
#ifndef HoldModeAction_h
#define HoldModeAction_h
#include "ModeAction.h"
#include "WaterPump.h"

class HoldModeAction : public ModeAction {
public:
  HoldModeAction();
  void setMode(WaterPump *waterPump);
};

#endif
