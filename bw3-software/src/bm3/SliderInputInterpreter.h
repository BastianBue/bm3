#pragma once
#include "InputInterpreter.h"

namespace bm3 { namespace core {

class SliderInputInterpreter : public InputInterpreter {
public:
    SliderInputInterpreter(bm3::hardware::Motor* leftMotor,
                           bm3::hardware::Motor* rightMotor,
                           bm3::hardware::ReflectanceSensor* leftSensor,
                           bm3::hardware::ReflectanceSensor* rightSensor,
                           bm3::hardware::BallShooter* ballShooter)
        : InputInterpreter(leftMotor, rightMotor, leftSensor, rightSensor, ballShooter) {}

    void interpretInput(int slider1, int slider2) override;
};

}}
