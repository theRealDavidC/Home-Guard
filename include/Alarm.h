#pragma once
#include <Arduino.h>

class Alarm {
public:
    Alarm(int buzzerPin, int redPin, int greenPin);
    void begin();
    void trigger();
    void reset();
    bool isActive();

private:
    void  sirensweep(int fromHz, int toHz, int stepHz, int stepDelay);
    void  setLED(bool red, bool green);

    int           _buzzerPin;
    int           _redPin;
    int           _greenPin;
    bool          _active;
    unsigned long _triggeredAt;
};
