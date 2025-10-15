#pragma once
#include "core/InputInterpreter.h"
#include "core/SliderInputInterpreter.h"
#include "hardware/Motor.h"
#include "hardware/ReflectanceSensor.h"
#include "hardware/BallShooter.h"
#include "types/State.h"

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
