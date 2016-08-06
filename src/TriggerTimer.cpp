#include "TriggerTimer.h"

TriggerTimer::TriggerTimer() {
  this->triggerTime = 1000;
  this->resetOnTrigger = true;
  this->lastPass = -1000; // so that this is triggered on first call
}

void TriggerTimer::setTriggerTime(long triggerTime) {
  this->triggerTime = triggerTime;
}

void TriggerTimer::reset() {
  this->lastPass = millis();
}

bool TriggerTimer::isTriggered() {
  if (millis() > (this->lastPass + this->triggerTime)) {
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

long TriggerTimer::getLastPass() {
  return this->lastPass;
}

void TriggerTimer::setLastPass(long lastPass) {
  this->lastPass = lastPass;
}

long TriggerTimer::getTriggerTime() {
  return this->triggerTime;
}
