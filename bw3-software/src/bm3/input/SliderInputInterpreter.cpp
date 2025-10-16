#include "input/SliderInputInterpreter.h"

namespace bm3 { namespace input {

void SliderInputInterpreter::interpretInput(int slider1, int slider2) {
    // Map slider1 (-100 to 100) to base speed (0 to 100)
    int baseSpeed = (slider1 + 100) / 2;
    // slider2 (-100 to 100) as tilt, mapped to -50 to 50
    int tilt = slider2 / 2;
    int leftSpeed = baseSpeed + tilt;
    int rightSpeed = baseSpeed - tilt;
    // Clamp speeds to 0..100
    if (leftSpeed < 0) leftSpeed = 0;
    if (leftSpeed > 100) leftSpeed = 100;
    if (rightSpeed < 0) rightSpeed = 0;
    if (rightSpeed > 100) rightSpeed = 100;
    if (leftMotor) leftMotor->forward(leftSpeed);
    if (rightMotor) rightMotor->forward(rightSpeed);
}

}}
