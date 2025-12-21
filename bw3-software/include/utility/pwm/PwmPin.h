#pragma once

#include "ESP32PWM.h"

class PwmPin
{
public:
    explicit PwmPin(const int pin) : pin_number(pin)
    {
    }

    void setup()
    {
        pwm_.attachPin(pin_number, 1000, 8);
    }

    void analogWrite(const uint8_t value)
    {
        pwm_.write(value);
    }

    int pin_number;

private:
    ESP32PWM pwm_;
};
