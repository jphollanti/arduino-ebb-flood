#pragma once
#ifndef WaitModeAction_h
#define WaitModeAction_h
#include "ModeAction.h"
#include "WaterPump.h"

class WaitModeAction : public ModeAction {
public:
  WaitModeAction();
  void setMode(WaterPump *waterPump);
};

#endif
