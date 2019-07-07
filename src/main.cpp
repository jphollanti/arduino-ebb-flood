#include <Arduino.h>

int pwm_out = 2;
int current_mode;
int counter_to_next_mode;
bool test = false;

char mode_names[3][5] = {
    "pump", 
    "hold", 
    "idle"
};

// pwm describes how fast the pump is
int mode_pwms[3] = {
  255, 
  65,
  0
};

// how long each mode should be kept on, in seconds
int mode_keep[3] = {
    8, 
    300, // 5 mins
    21600, // 6 h
};

void setup() {
    current_mode = 2; // start from last, will roll back to beginning on start
    counter_to_next_mode = 0;
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(9600);

    pinMode(pwm_out, OUTPUT);
    analogWrite(pwm_out, 0);

    // pins 3 & 4 control direction
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
}

void loop() {
    counter_to_next_mode--;
    
    Serial.print("mode: ");
    Serial.print(mode_names[current_mode]);
    Serial.print(" (");
    Serial.print(current_mode);
    Serial.print(")");
    Serial.print(", time to next mode: ");
    Serial.print(counter_to_next_mode);
    Serial.print(", pwm: ");
    Serial.println(mode_pwms[current_mode]);
    
    //digitalWrite(LED_BUILTIN, LOW);

    if (counter_to_next_mode <= 0) {
        if (current_mode == 2) {
            current_mode = 0;
        } else {
            current_mode++;
        }

        // debugging only
        if (current_mode != 2) {
            digitalWrite(LED_BUILTIN, HIGH);
        } else {
            digitalWrite(LED_BUILTIN, LOW);
        }

        counter_to_next_mode = mode_keep[current_mode];
        analogWrite(pwm_out, mode_pwms[current_mode]);
    }

    delay(1000); // once per second
}