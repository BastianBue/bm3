#include "bm3/state/StateMachine.h"

#include <utility>
#include "bm3/state/State.h"

using bm3::state::State;

namespace bm3
{
    namespace state
    {
        StateMachine::StateMachine(State initialState, ReflectanceSensor leftReflectanceSensor,
                                   ReflectanceSensor rightReflectanceSensor) :
            leftReflectanceSensor(std::move(leftReflectanceSensor)),
            rightReflectanceSensor(std::move(rightReflectanceSensor))
        {
            state = initialState;
            lineCrossedAt = millis();
        }

        void StateMachine::update()
        {
            leftReflectanceSensor.update();
            rightReflectanceSensor.update();

            if (this->state == State::LINE_CROSSED)
            {
                unsigned long elapsed = millis() - lineCrossedAt;
                if (elapsed >= 2000)
                {
                    Serial.println("2000ms elapsed, entering Default State");
                    this->state = State::DEFAULT_STATE;
                }
            }

            if (this->state == State::DEFAULT_STATE)
            {
                if (leftReflectanceSensor.isDark() || rightReflectanceSensor.isDark())
                {
                    this->state = State::LINE_CROSSED;
                    this->lineCrossedAt = millis();
                    Serial.println("Line crossed, entering line crossed state");
                }
            }
        }

        State StateMachine::getState() const
        {
            return this->state;
        }
    }
}
