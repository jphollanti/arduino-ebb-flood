#include "IrrigationController.h"
#include "TriggerTimer.h"
#include "TimeUnit.h"
#include "SecondTimeUnit.h"
#include "MinuteTimeUnit.h"
#include "HourTimeUnit.h"

int IrrigationController::PUMP = 0;
int IrrigationController::HOLD = 1;
int IrrigationController::WAIT = 2;
int IrrigationController::INIT = 3;

int IrrigationController::modeTransitions[4] = {
  IrrigationController::HOLD, // from pump
  IrrigationController::WAIT, // from hold
  IrrigationController::PUMP, // from wait
  IrrigationController::PUMP  // from init
};

IrrigationController::IrrigationController() {

}

void IrrigationController::setDefaults() {
    this->pumpTime = new SecondTimeUnit(27);
    this->holdTime = new SecondTimeUnit(120);
    this->waitTime = new HourTimeUnit(6);
}

void IrrigationController::initialize() {
    this->triggerTimer = new TriggerTimer();
    this->triggerTimer->setTriggerTime(this->pumpTime->getMilliseconds());
    this->triggerTimer->initialize();
    this->mode = IrrigationController::INIT;
}

int IrrigationController::getMode() {
  return this->mode;
}

bool IrrigationController::tick() {
  if (this->triggerTimer->isTriggered()) {
    this->mode = IrrigationController::modeTransitions[this->mode];
    return true;
  } else {
    return false;
  }
}

TriggerTimer* IrrigationController::getTriggerTimer() {
  return this->triggerTimer;
}

void IrrigationController::setPumpTime(TimeUnit *time) {
  this->pumpTime = time;
}
void IrrigationController::setHoldTime(TimeUnit *time) {
  this->holdTime = time;
}
void IrrigationController::setWaitTime(TimeUnit *time) {
  this->waitTime = time;
}
