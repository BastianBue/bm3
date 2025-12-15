#include "bm3/input/SliderInputInterpreter.h"

#include <HardwareSerial.h>

#include "../../../include/utility/Log.h"
#include "resources/ApplicationProperties.h"

using bm3::peripheral::Motor;
using bm3::peripheral::ReflectanceSensor;
using bm3::peripheral::BallShooter;

namespace bm3
{
    namespace input
    {
        SliderInputInterpreter::SliderInputInterpreter(
            Motor* leftMotor,
            Motor* rightMotor,
            ReflectanceSensor* leftSensor,
            ReflectanceSensor* rightSensor,
            BallShooter* ballShooter,
            const ApplicationProperties& config)
            : InputInterpreter(leftMotor, rightMotor, leftSensor, rightSensor, ballShooter), config(config)
        {
        }

        void SliderInputInterpreter::interpretInput(const int vertical_slider, const int horizontal_slider)
        {
            LOG("SliderInputInterpreter::interpretInput");
            if (100 < vertical_slider || vertical_slider < -100)
            {
                LOG("Vertical Slider out of Bounds: " + String(vertical_slider));
                return;
            }
            if (100 < horizontal_slider || horizontal_slider < -100)
            {
                LOG("Horizontal Slider out of Bounds: " + String(horizontal_slider));
                return;
            }

            const bool backwards = vertical_slider < 0;
            const bool forwards = vertical_slider > 0;
            const bool standstill = !forwards && !backwards;

            const bool left = horizontal_slider < 0;
            const bool right = horizontal_slider > 0;
            const bool straight = !left && !right;

            const int speed = std::abs(vertical_slider);
            const int tilt = static_cast<int>(std::abs(horizontal_slider) * config.tiltPercentage * speed / 100.0); // max tilt is 75% of speed

            const int rotation = static_cast<int>(std::abs(horizontal_slider) * config.rotationPercentage); // rotation speed when standstill would be to fast at max

            int speed_left = 0;
            int speed_right = 0;
            if (left)
            {
                speed_left = speed;
                speed_right = speed - tilt;
            }
            else if (right)
            {
                speed_left = speed - tilt;
                speed_right = speed;
            }
            else if (straight)
            {
                speed_left = speed;
                speed_right = speed;
            }

            if (forwards)
            {
                leftMotor->forward(speed_left);
                rightMotor->forward(speed_right);
            }
            else if (backwards)
            {
                leftMotor->backward(speed_left);
                rightMotor->backward(speed_right);
            }
            else if (standstill && right)
            {
                leftMotor->backward(rotation);
                rightMotor->forward(rotation);
            }
            else if (standstill && left)
            {
                leftMotor->backward(rotation);
                rightMotor->forward(rotation);
            }
            else if (standstill && straight)
            {
                leftMotor->stop();
                rightMotor->stop();
            }
        }
    }
}
