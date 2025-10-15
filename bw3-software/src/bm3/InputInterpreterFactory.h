#pragma once
#include "InputInterpreter.h"
#include "SliderInputInterpreter.h"
#include "Motor.h"
#include "ReflectanceSensor.h"
#include "BallShooter.h"
#include "State.h"

namespace bm3 { namespace control {

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
