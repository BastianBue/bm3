#pragma once

#include "bm3/input/InputInterpreter.h"
#include "bm3/peripheral/Motor.h"
#include "bm3/peripheral/ReflectanceSensor.h"

using bm3::peripheral::Motor;
using bm3::peripheral::ReflectanceSensor;

namespace bm3 { namespace input {

class OverriddenInputInterpreter : public InputInterpreter {
public:
    OverriddenInputInterpreter(Motor* leftMotor,
                               Motor* rightMotor,
                               ReflectanceSensor* leftSensor,
                               ReflectanceSensor* rightSensor)
        : InputInterpreter(leftMotor, rightMotor, leftSensor, rightSensor, nullptr) {}
    void interpretInput(int slider1, int slider2) override {
        // Example: stop both motors when overridden
        if (leftMotor) leftMotor->stop();
        if (rightMotor) rightMotor->stop();
    }
};

}}
