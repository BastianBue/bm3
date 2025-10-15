#include <Arduino.h>
#include "Motor.h"

namespace bm3 { namespace hardware {

Motor::Motor(int pinA, int pinB)
    : pinA(pinA), pinB(pinB) {
    // Pin mode setup moved to setup()
}

void Motor::setup() {
    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
}

void Motor::forward(int speed) {
    int pwm = map(speed, 0, 100, 0, 255);
    analogWrite(pinA, pwm); // speed PWM
    analogWrite(pinB, 0);   // direction LOW
}

void Motor::backward(int speed) {
    int pwm = map(speed, 0, 100, 0, 255);
    analogWrite(pinA, 0);   // direction LOW
    analogWrite(pinB, pwm); // speed PWM
}

void Motor::stop() {
    analogWrite(pinA, 0);
    analogWrite(pinB, 0);
}

}}
