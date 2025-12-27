#include "bm3/state/StateMachine.h"

#include <utility>

#include "bm3/state/State.h"

using bm3::state::State;

namespace bm3
{
    namespace state
    {
        StateMachine::StateMachine(State initialState, ReflectanceSensor leftReflectanceSensor,
                                   ReflectanceSensor rightReflectanceSensor,
                                   const ApplicationProperties& appProperties) :
            leftReflectanceSensor(std::move(leftReflectanceSensor)),
            rightReflectanceSensor(std::move(rightReflectanceSensor)),
            appProperties(appProperties)
        {
            state = initialState;
            lineCrossedAt = millis();
        }

        void StateMachine::update()
        {
            leftReflectanceSensor.update();
            rightReflectanceSensor.update();

            if (!appProperties.disalbeStateMachine)
            {
                if (this->state == State::LINE_CROSSED)
                {
                    unsigned long elapsed = millis() - lineCrossedAt;
                    if (elapsed >= 2000)
                    {
                        this->state = State::DEFAULT_STATE;
                    }
                }

                if (this->state == State::DEFAULT_STATE)
                {
                    if (leftReflectanceSensor.isDark() || rightReflectanceSensor.isDark())
                    {
                        this->state = State::LINE_CROSSED;
                        this->lineCrossedAt = millis();
                    }
                }
            }
        }

        State StateMachine::getState() const
        {
            return this->state;
        }
    }
}
