#include "bm3/input/OverriddenInputInterpreter.h"


using bm3::peripheral::Motor;
using bm3::peripheral::ReflectanceSensor;

namespace bm3
{
    namespace input
    {
        // ...OverriddenInputInterpreter implementation...
        void OverriddenInputInterpreter::interpretInput(int slider1, int slider2)
        {
            // Example: stop both motors when overridden
            if (leftMotor) leftMotor->backward(50);
            if (rightMotor) rightMotor->backward(50);
        }
    }
}
