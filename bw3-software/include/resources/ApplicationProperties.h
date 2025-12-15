#pragma once
#include <WString.h>

#include "ApplicationProperties.Development.h"
#include "ApplicationProperties.Productions.h"

struct ApplicationProperties
{
    float tiltPercentage;
    float rotationPercentage;
    int motorMinimumThreshold;
};

inline ApplicationProperties loadProfileConfig() {
    ApplicationProperties config;
    config.tiltPercentage = TILT_PERCENTAGE;
    config.rotationPercentage = ROTATION_PERCENTAGE;
    config.motorMinimumThreshold = MOTOR_MINIMUM_THRESHOLD;
    return config;
}
