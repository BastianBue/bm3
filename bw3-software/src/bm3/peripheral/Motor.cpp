#include <Arduino.h>
#include "bm3/peripheral/Motor.h"

namespace bm3 { namespace peripheral {

Motor::Motor(const int pinA, const int pinB)
    : pinA(pinA), pinB(pinB) {
}

void Motor::setup() {
    Serial.println("Motor::setup");

    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
}

void Motor::forward(const int speed) const
{
    if (speed < 0 || speed > 100)
    {
        Serial.println("Motor::forward: invalid speed: " + String(speed));
        return;
    }

    const int pwm = map(speed, 0, 100, 120, 255); // from 120 to 255, because below 120 the car does not move on the ground
    analogWrite(pinA, pwm); // speed PWM
    analogWrite(pinB, 0);   // direction LOW
}

void Motor::backward(const int speed) const{
    if (speed < 0 || speed > 100)
    {
        Serial.println("Motor::forward: invalid speed: " + String(speed));
        return;
    }

    const int pwm = map(speed, 0, 100, 120, 255); // from 120 to 255, because below 120 the car does not move on the ground
    analogWrite(pinA, 0);   // direction LOW
    analogWrite(pinB, pwm); // speed PWM
}

void Motor::stop() const
{
    analogWrite(pinA, 0);
    analogWrite(pinB, 0);
}

}}
