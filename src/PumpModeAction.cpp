#include "PumpModeAction.h"
#include "WaterPump.h"

PumpModeAction::PumpModeAction() {
}

void PumpModeAction::setMode(WaterPump *waterPump) {
  waterPump->setPwm(255);
}
