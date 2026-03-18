#include "LightSensor.h"
#include "config.h"

LightSensor::LightSensor(int pin) : _pin(pin) {}

void LightSensor::begin() {
    pinMode(_pin, INPUT);
}

bool LightSensor::isNight() {
    return analogRead(_pin) < Config::DARK_THRESHOLD;
}

int LightSensor::rawValue() {
    return analogRead(_pin);
}
