#pragma once
#include <Arduino.h>

class MotionSensor {
public:
    explicit MotionSensor(int pin);
    void begin();
    bool detected();

private:
    int           _pin;
    unsigned long _lastTriggerTime;
};
