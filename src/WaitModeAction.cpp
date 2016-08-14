#include "WaitModeAction.h"
#include "WaterPump.h"

WaitModeAction::WaitModeAction() {
}

void WaitModeAction::setMode(WaterPump *waterPump) {
  waterPump->setPwm(0);
}
