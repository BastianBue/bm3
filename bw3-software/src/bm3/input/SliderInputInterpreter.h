#pragma once

#include "bm3/input/InputInterpreter.h"
#include "bm3/peripheral/Motor.h"
#include "bm3/peripheral/ReflectanceSensor.h"
#include "bm3/peripheral/BallShooter.h"
#include "resources/ApplicationProperties.h"

using bm3::peripheral::Motor;
using bm3::peripheral::ReflectanceSensor;
using bm3::peripheral::BallShooter;

namespace bm3
{
    namespace input
    {
        class SliderInputInterpreter final : public InputInterpreter
        {
        public:
            SliderInputInterpreter(
                Motor* leftMotor,
                Motor* rightMotor,
                ReflectanceSensor* leftSensor,
                ReflectanceSensor* rightSensor,
                BallShooter* ballShooter,
                const ApplicationProperties& config
            );
            void interpretInput(int vertical_slider, int horizontal_slider) override;
        private:
            ApplicationProperties config;
        };
    }
}
