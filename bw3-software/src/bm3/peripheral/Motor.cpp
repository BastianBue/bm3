#include <Arduino.h>
#include "bm3/peripheral/Motor.h"

namespace bm3
{
    namespace peripheral
    {
        Motor::Motor(PwmPin* pinA, PwmPin* pinB, PwmSink* sink)
            : pinA(pinA), pinB(pinB), sink(sink)
        {
        }

        void Motor::setup()
        {
            Serial.println("Motor::setup");
            pinA->setup();
            pinB->setup();
        }

        void Motor::forward(const int speed) const
        {
            if (speed < 0 || speed > 100)
            {
                Serial.println("Motor::forward: invalid speed: " + String(speed));
                return;
            }
            const int pwm = map(speed, 0, 100, 120, 255);
            sink->set(pinA, pwm);
            sink->set(pinB, 0);
        }

        void Motor::backward(const int speed) const
        {
            if (speed < 0 || speed > 100)
            {
                Serial.println("Motor::backward: invalid speed: " + String(speed));
                return;
            }
            const int pwm = map(speed, 0, 100, 120, 255);
            sink->set(pinA, 0);
            sink->set(pinB, pwm);
        }

        void Motor::stop() const
        {
            sink->set(pinA, 0);
            sink->set(pinB, 0);
        }
    }
}
