07-07-2019

started a new crop with garden cress and japanese greens mizuna. 

garden cress should produce harvest in 10 days, japanese greens mizuna in 12 days. 

timers and pwms in use: 

```
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
```

all goes well, i should add some nutrition solution to the water in 4-5 days.