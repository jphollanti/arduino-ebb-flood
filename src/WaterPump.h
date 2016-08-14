#ifndef WaterPump_h
#define WaterPump_h

class WaterPump {
  private:
    int pin1;
    int pin2;

  public:
    WaterPump(int pin1, int pin2);
    void setPwm(float pwm);
    bool isOn();
};
#endif
