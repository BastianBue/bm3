#include "input/InputInterpreterFactory.h"
#include "input/SliderInputInterpreter.h"
#include "input/OverriddenInputInterpreter.h"
#include "state/State.h"

namespace bm3 { namespace input {

bm3::core::InputInterpreter* InputInterpreterFactory::createInterpreter(
    bm3::types::State state,
    bm3::hardware::Motor* leftMotor,
    bm3::hardware::Motor* rightMotor,
    bm3::hardware::ReflectanceSensor* leftSensor,
    bm3::hardware::ReflectanceSensor* rightSensor,
    bm3::hardware::BallShooter* ballShooter)
{
    if (state == bm3::types::State::DEFAULT) {
        return new bm3::core::SliderInputInterpreter(leftMotor, rightMotor, leftSensor, rightSensor, ballShooter);
    }
    if (state == bm3::types::State::LINE_CROSSED) {
        return new bm3::core::OverriddenInputInterpreter(leftMotor, rightMotor, leftSensor, rightSensor);
    }
    return nullptr;
}

}}
