#pragma once

#include "bm3/peripheral/Motor.h"
#include "bm3/peripheral/ReflectanceSensor.h"
#include "bm3/peripheral/BallShooter.h"

using bm3::peripheral::Motor;
using bm3::peripheral::ReflectanceSensor;
using bm3::peripheral::BallShooter;

namespace bm3 { namespace input {

class InputInterpreter {
public:
    virtual void interpretInput(int slider1, int slider2) = 0;
    virtual ~InputInterpreter() = default;
protected:
    Motor* leftMotor;
    Motor* rightMotor;
    ReflectanceSensor* leftSensor;
    ReflectanceSensor* rightSensor;
    BallShooter* ballShooter;
    InputInterpreter(Motor* leftMotor,
                     Motor* rightMotor,
                     ReflectanceSensor* leftSensor,
                     ReflectanceSensor* rightSensor,
                     BallShooter* ballShooter)
        : leftMotor(leftMotor), rightMotor(rightMotor),
          leftSensor(leftSensor), rightSensor(rightSensor),
          ballShooter(ballShooter) {}
};

}}

