#include "Alarm.h"
#include "config.h"

Alarm::Alarm(int buzzerPin, int redPin, int greenPin)
    : _buzzerPin(buzzerPin),
      _redPin(redPin),
      _greenPin(greenPin),
      _active(false),
      _triggeredAt(0) {}

void Alarm::begin() {
    pinMode(_buzzerPin, OUTPUT);
    pinMode(_redPin,    OUTPUT);
    pinMode(_greenPin,  OUTPUT);
    reset();
}

void Alarm::trigger() {
    if (_active) return;

    _active      = true;
    _triggeredAt = millis();

    Serial.println("[Alarm] *** INTRUDER DETECTED — ALARM TRIGGERED ***");

    setLED(true, false);

    // Play 3 cycles of rising + falling siren
    for (int i = 0; i < 3; i++) {
        sirensweep(Config::SIREN_LOW_HZ,  Config::SIREN_HIGH_HZ, Config::SIREN_STEP_HZ, Config::SIREN_STEP_DELAY);
        sirensweep(Config::SIREN_HIGH_HZ, Config::SIREN_LOW_HZ,  Config::SIREN_STEP_HZ, Config::SIREN_STEP_DELAY);
    }

    noTone(_buzzerPin);
}

void Alarm::reset() {
    _active = false;
    noTone(_buzzerPin);
    setLED(false, true);
    Serial.println("[Alarm] System armed — monitoring.");
}

bool Alarm::isActive() {
    if (_active && (millis() - _triggeredAt) > Config::ALARM_DURATION_MS) {
        reset();
    }
    return _active;
}

void Alarm::sirensweep(int fromHz, int toHz, int stepHz, int stepDelay) {
    int step = (fromHz < toHz) ? stepHz : -stepHz;
    for (int freq = fromHz; (step > 0) ? (freq <= toHz) : (freq >= toHz); freq += step) {
        tone(_buzzerPin, freq);
        delay(stepDelay);
    }
}

void Alarm::setLED(bool red, bool green) {
    digitalWrite(_redPin,   red   ? HIGH : LOW);
    digitalWrite(_greenPin, green ? HIGH : LOW);
}
