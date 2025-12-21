#include <Arduino.h>
#include "bm3/peripheral/Motor.h"

#include "../../../include/utility/Log.h"

namespace bm3
{
    namespace peripheral
    {
        Motor::Motor(PwmPin* pinA, PwmPin* pinB, PwmSink* sink, const char* descriptor, const ApplicationProperties& config)
            : pinA(pinA), pinB(pinB), sink(sink), descriptor(descriptor), config(config)
        {
        }

        void Motor::setup()
        {
            LOG(String(descriptor) + ": setup");
            pinA->setup();
            pinB->setup();
        }

        void Motor::forward(const int speed) const
        {
            if (speed < 0 || speed > 100)
            {
                LOG(String(descriptor) + ": forward: invalid speed: " + String(speed));
                return;
            }

            LOG(String(descriptor) + " forward: " + String(speed));
            const int pwm = map(speed, 0, 100, config.motorMinimumThreshold, config.motorMaximumThreshold);
            sink->set(pinA, pwm);
            sink->set(pinB, 0);
        }

        void Motor::backward(const int speed) const
        {
            if (speed < 0 || speed > 100)
            {
                LOG(String(descriptor) + ": backward: invalid speed: " + String(speed));
                return;
            }

            LOG(String(descriptor) + " backward: " + String(speed));
            const int pwm = map(speed, 0, 100, config.motorMinimumThreshold, config.motorMaximumThreshold);
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
