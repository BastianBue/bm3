#pragma once

#include "ESP32PWM.h"

class PwmPin
{
public:
    explicit PwmPin(const int pin) : pin_(pin) {}

    void setup() {
        pwm_.attachPin(pin_, 1000, 8);
    }

    void analogWrite(const uint8_t value) {
        pwm_.write(value);
    }

private:
    int pin_;
    ESP32PWM pwm_;
};

