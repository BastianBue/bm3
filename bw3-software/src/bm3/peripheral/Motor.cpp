#include <Arduino.h>
#include "bm3/peripheral/Motor.h"

namespace bm3 { namespace peripheral {

Motor::Motor(PwmPin* pinA, PwmPin* pinB)
    : pinA(pinA), pinB(pinB) {
}

void Motor::setup() {
    Serial.println("Motor::setup");
    if (pinA) pinA->setup();
    if (pinB) pinB->setup();
}

void Motor::forward(const int speed) const
{
    if (speed < 0 || speed > 100)
    {
        Serial.println("Motor::forward: invalid speed: " + String(speed));
        return;
    }
    const int pwm = map(speed, 0, 100, 120, 255);
    if (pinA) pinA->analogWrite(pwm);
    if (pinB) pinB->analogWrite(0);
}

void Motor::backward(const int speed) const{
    if (speed < 0 || speed > 100)
    {
        Serial.println("Motor::backward: invalid speed: " + String(speed));
        return;
    }
    const int pwm = map(speed, 0, 100, 120, 255);
    if (pinA) pinA->analogWrite(0);
    if (pinB) pinB->analogWrite(pwm);
}

void Motor::stop() const
{
    if (pinA) pinA->analogWrite(0);
    if (pinB) pinB->analogWrite(0);
}

}}
