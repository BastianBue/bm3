#pragma once
#include "input/InputInterpreter.h"

namespace bm3 { namespace input {

class OverriddenInputInterpreter : public InputInterpreter {
public:
    OverriddenInputInterpreter(bm3::hardware::Motor* leftMotor,
                               bm3::hardware::Motor* rightMotor,
                               bm3::hardware::ReflectanceSensor* leftSensor,
                               bm3::hardware::ReflectanceSensor* rightSensor)
        : InputInterpreter(leftMotor, rightMotor, leftSensor, rightSensor, nullptr) {}
    void interpretInput(int slider1, int slider2) override {
        // Example: stop both motors when overridden
        if (leftMotor) leftMotor->stop();
        if (rightMotor) rightMotor->stop();
    }
};

}}
