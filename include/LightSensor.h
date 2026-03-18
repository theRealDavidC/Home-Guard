#pragma once
#include <Arduino.h>

class LightSensor {
public:
    explicit LightSensor(int pin);
    void begin();
    bool isNight();
    int  rawValue();

private:
    int _pin;
};
