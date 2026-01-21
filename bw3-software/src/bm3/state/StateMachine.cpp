#include "bm3/state/StateMachine.h"

#include <utility>

#include "../../../include/utility/Log.h"
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

        void StateMachine::update(const bool on)
        {
            leftReflectanceSensor.update();
            rightReflectanceSensor.update();

            if (!appProperties.disalbeStateMachine && on)
            {
                if (this->state == State::LINE_CROSSED)
                {
                    unsigned long elapsed = millis() - lineCrossedAt;
                    if (elapsed >= 2000)
                    {
                        LOG("2000ms elapsed, entering Default State");
                        this->state = State::DEFAULT_STATE;
                    }
                }

                if (this->state == State::DEFAULT_STATE)
                {
                    if (leftReflectanceSensor.isDark() || rightReflectanceSensor.isDark())
                    {
                        this->state = State::LINE_CROSSED;
                        this->lineCrossedAt = millis();
                        LOG("Line crossed, entering line crossed state");
                    }
                }
            }

            if (!on)
                this->state = State::DEFAULT_STATE;
            {
            }
        }

        State StateMachine::getState() const
        {
            return this->state;
        }
    }
}
