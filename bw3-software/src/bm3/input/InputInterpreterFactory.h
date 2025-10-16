#pragma once
#include "input/InputInterpreter.h"
#include "input/SliderInputInterpreter.h"
#include "peripheral/Motor.h"
#include "peripheral/ReflectanceSensor.h"
#include "peripheral/BallShooter.h"
#include "state/State.h"

namespace bm3 { namespace input {

class InputInterpreterFactory {
public:
    static bm3::core::InputInterpreter* createInterpreter(
        bm3::types::State state,
        bm3::hardware::Motor* leftMotor,
        bm3::hardware::Motor* rightMotor,
        bm3::hardware::ReflectanceSensor* leftSensor,
        bm3::hardware::ReflectanceSensor* rightSensor,
        bm3::hardware::BallShooter* ballShooter);
};

}}
