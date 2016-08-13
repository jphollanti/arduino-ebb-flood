#include "IrrigationController.h"
#include "TriggerTimer.h"
#include "TimeUnit.h"
#include "SecondTimeUnit.h"
#include "MinuteTimeUnit.h"
#include "HourTimeUnit.h"

int IrrigationController::PUMP = 1;
int IrrigationController::HOLD = 2;
int IrrigationController::WAIT = 3;
int IrrigationController::INIT = 4;

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
    if (this->mode == IrrigationController::INIT) {
      this->mode = IrrigationController::PUMP;
      return true;
    }
    if (this->mode == IrrigationController::PUMP) {
      this->mode = IrrigationController::HOLD;
      return true;
    }
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
