#pragma once
#ifndef PumpModeAction_h
#define PumpModeAction_h
#include "ModeAction.h"
#include "WaterPump.h"

class PumpModeAction : public ModeAction {
public:
  PumpModeAction();
  void setMode(WaterPump *waterPump);
};

#endif
