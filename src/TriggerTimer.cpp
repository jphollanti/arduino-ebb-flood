#include "TriggerTimer.h"

TriggerTimer::TriggerTimer() {
  this->triggerTime = 1000;
  this->resetOnTrigger = true;
}

void TriggerTimer::initialize() {
  this->lastPass = -this->triggerTime; // so that this is triggered on first call
}

void TriggerTimer::setTriggerTime(long triggerTime) {
  this->triggerTime = triggerTime;
}

long TriggerTimer::getTriggerTime() {
  return this->triggerTime;
}

void TriggerTimer::reset() {
  this->lastPass = millis();
}

bool TriggerTimer::isTriggered() {
  bool triggered = millis() > (this->lastPass + this->triggerTime);
  if (triggered) {
    if (this->isResetOnTrigger()) {
      this->reset();
    }
    return true;
  }
  return false;

}

bool TriggerTimer::isResetOnTrigger() {
  return this->resetOnTrigger;
}

void TriggerTimer::setResetOnTrigger(bool resetOnTrigger) {
  this->resetOnTrigger = resetOnTrigger;
}

void TriggerTimer::setLastPass(long lastPass) {
  this->lastPass = lastPass;
}

long TriggerTimer::getLastPass() {
  return this->lastPass;
}
