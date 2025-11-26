#include "bm3/input/InputInterpreterFactory.h"
#include "bm3/input/SliderInputInterpreter.h"
#include "bm3/input/OverriddenInputInterpreter.h"
#include "bm3/state/State.h"

using bm3::peripheral::Motor;
using bm3::peripheral::ReflectanceSensor;
using bm3::peripheral::BallShooter;
using bm3::state::State;

namespace bm3
{
    namespace input
    {
        InputInterpreter* InputInterpreterFactory::createInterpreter(
            const State state,
            Motor* leftMotor,
            Motor* rightMotor
            // ReflectanceSensor* leftSensor,
            // ReflectanceSensor* rightSensor,
            // BallShooter* ballShooter
        )
        {
            if (state == State::DEFAULT_STATE)
            {
                return new SliderInputInterpreter(leftMotor, rightMotor, nullptr, nullptr, nullptr);
            }
            if (state == State::LINE_CROSSED)
            {
                return new OverriddenInputInterpreter(leftMotor, rightMotor, nullptr, nullptr, nullptr);
            }
            return nullptr;
        }
    }
}
