#ifndef TriggerTimer_h
#define TriggerTimer_h
#include <Arduino.h>

class TriggerTimer {
  private:
    long triggerTime;
    long lastPass;
    bool resetOnTrigger;
  public:
    TriggerTimer();
    void reset();
    void setTriggerTime(long triggerTime);
    void setResetOnTrigger(bool resetOnTrigger);
    bool isResetOnTrigger();
    bool isTriggered();
    long getLastPass();
    void setLastPass(long lastPass);
    long getTriggerTime();
};;

#endif
