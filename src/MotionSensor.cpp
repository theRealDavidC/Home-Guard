#include "MotionSensor.h"
#include "config.h"

MotionSensor::MotionSensor(int pin)
    : _pin(pin), _lastTriggerTime(0) {}

void MotionSensor::begin() {
    pinMode(_pin, INPUT);
    Serial.println("[Motion] Warming up PIR sensor...");
    delay(Config::PIR_WARMUP_MS);
    Serial.println("[Motion] PIR ready.");
}

bool MotionSensor::detected() {
    if (digitalRead(_pin) == HIGH) {
        unsigned long now = millis();
        if ((now - _lastTriggerTime) > Config::MOTION_COOLDOWN_MS) {
            _lastTriggerTime = now;
            return true;
        }
    }
    return false;
}
