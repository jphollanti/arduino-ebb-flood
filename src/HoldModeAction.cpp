#include "HoldModeAction.h"
#include "WaterPump.h"

HoldModeAction::HoldModeAction() {
}

void HoldModeAction::setMode(WaterPump *waterPump) {
  waterPump->setPwm(72);
}
