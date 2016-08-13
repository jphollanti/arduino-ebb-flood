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
    void initialize();
    void reset();
    void setTriggerTime(long triggerTime);
    long getTriggerTime();
    void setResetOnTrigger(bool resetOnTrigger);
    bool isResetOnTrigger();
    bool isTriggered();
    void setLastPass(long lastPass);
    long getLastPass();
};;

#endif
