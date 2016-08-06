#include "IrrigationController.h"
#include "TriggerTimer.h"

int IrrigationController::PUMP = 1;

IrrigationController::IrrigationController() {
  this->triggerTimer = new TriggerTimer();
}

int IrrigationController::getMode() {
  return IrrigationController::PUMP;
}

bool IrrigationController::tick() {
  return this->triggerTimer->isTriggered();
}

TriggerTimer* IrrigationController::getTriggerTimer() {
  return this->triggerTimer;
}
