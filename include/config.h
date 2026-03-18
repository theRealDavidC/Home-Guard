#pragma once

namespace Config {

    // --- Pins ---
    constexpr int PIR_PIN       = 13;
    constexpr int BUZZER_PIN    = 14;
    constexpr int LED_RED_PIN   = 2;
    constexpr int LED_GREEN_PIN = 4;
    constexpr int LDR_PIN       = 34;   // Analog pin (light sensor)

    // --- Serial ---
    constexpr int BAUD_RATE = 115200;

    // --- Light Sensor ---
    constexpr int DARK_THRESHOLD = 1500;  // Below this = night (0–4095 range)

    // --- Alarm ---
    constexpr int ALARM_DURATION_MS  = 10000; // How long alarm stays active
    constexpr int SIREN_HIGH_HZ      = 1800;
    constexpr int SIREN_LOW_HZ       = 800;
    constexpr int SIREN_STEP_HZ      = 15;
    constexpr int SIREN_STEP_DELAY   = 5;     // ms between frequency steps

    // --- Motion ---
    constexpr int PIR_WARMUP_MS      = 30000; // PIR sensor warmup time
    constexpr int MOTION_COOLDOWN_MS = 3000;  // Ignore re-triggers during alarm
}
