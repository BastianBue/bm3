#pragma once
#include "State.h"
#include "bm3/input/InputInterpreterFactory.h"
#include "resources/ApplicationProperties.h"

namespace bm3
{
    namespace state
    {
        class StateMachine
        {
        public:
            StateMachine(State initialState, ReflectanceSensor leftReflectanceSensor,
                         ReflectanceSensor rightReflectanceSensor,
                         const ApplicationProperties& appProperties);
            void update();
            State getState() const;
        private:
            State state;
            unsigned long lineCrossedAt;

            ReflectanceSensor leftReflectanceSensor;
            ReflectanceSensor rightReflectanceSensor;
            ApplicationProperties appProperties;
        };
    }
}
