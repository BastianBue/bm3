#pragma once
#include "Motor.h"
#include "ReflectanceSensor.h"
#include "BallShooter.h"

namespace bm3 { namespace core {

class InputInterpreter {
public:
    virtual void interpretInput(int slider1, int slider2) = 0;
    virtual ~InputInterpreter() {}
protected:
    bm3::hardware::Motor* leftMotor;
    bm3::hardware::Motor* rightMotor;
    bm3::hardware::ReflectanceSensor* leftSensor;
    bm3::hardware::ReflectanceSensor* rightSensor;
    bm3::hardware::BallShooter* ballShooter;
    InputInterpreter(bm3::hardware::Motor* leftMotor,
                     bm3::hardware::Motor* rightMotor,
                     bm3::hardware::ReflectanceSensor* leftSensor,
                     bm3::hardware::ReflectanceSensor* rightSensor,
                     bm3::hardware::BallShooter* ballShooter)
        : leftMotor(leftMotor), rightMotor(rightMotor),
          leftSensor(leftSensor), rightSensor(rightSensor),
          ballShooter(ballShooter) {}
};

}}
