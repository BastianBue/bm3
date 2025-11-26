#pragma once
#include "State.h"
#include "bm3/input/InputInterpreterFactory.h"

namespace bm3
{
    namespace state
    {
        class StateMachine
        {
        public:
            explicit StateMachine(State initialState, ReflectanceSensor leftReflectanceSensor,
                                  ReflectanceSensor rightReflectanceSensor);
            void update();
            State getState() const;
        private:
            State state;
            unsigned long lineCrossedAt;

            ReflectanceSensor leftReflectanceSensor;
            ReflectanceSensor rightReflectanceSensor;
        };
    }
}
