#include <Arduino.h>
#include "config.h"
#include "MotionSensor.h"
#include "LightSensor.h"
#include "Alarm.h"

MotionSensor motion(Config::PIR_PIN);
LightSensor  light(Config::LDR_PIN);
Alarm        alarm(Config::BUZZER_PIN, Config::LED_RED_PIN, Config::LED_GREEN_PIN);

void setup() {
    Serial.begin(Config::BAUD_RATE);
    Serial.println("=== HomeGuard Initializing ===");

    light.begin();
    alarm.begin();
    motion.begin();   // Last — blocks during PIR warmup

    Serial.println("=== HomeGuard Active ===");
}

void loop() {
    alarm.isActive();  // Auto-reset check

    if (!alarm.isActive() && light.isNight() && motion.detected()) {
        Serial.printf("[Light] Raw: %d | Night: YES | Motion: DETECTED\n", light.rawValue());
        alarm.trigger();
    }
}
