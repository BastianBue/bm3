#pragma once

#include "bm3/input/InputInterpreter.h"
#include "bm3/peripheral/Motor.h"
#include "bm3/peripheral/ReflectanceSensor.h"
#include "bm3/peripheral/BallShooter.h"
#include "bm3/state/State.h"

using bm3::peripheral::Motor;
using bm3::peripheral::ReflectanceSensor;
using bm3::peripheral::BallShooter;
using bm3::state::State;

namespace bm3 { namespace input {

class InputInterpreterFactory {
public:
    static InputInterpreter* createInterpreter(
        State state,
        Motor* leftMotor,
        Motor* rightMotor
        // ReflectanceSensor* leftSensor,
        // ReflectanceSensor* rightSensor,
        // BallShooter* ballShooter
        );
};

}}
