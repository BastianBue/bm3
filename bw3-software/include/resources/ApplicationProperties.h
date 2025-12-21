#pragma once

struct ApplicationProperties
{
    float tiltPercentage;
    float rotationPercentage;
    int motorMinimumThreshold;
};

inline ApplicationProperties loadProfileConfig()
{
    ApplicationProperties config;
    config.tiltPercentage = 0.93f;
    config.rotationPercentage = 0.5f;
    config.motorMinimumThreshold = 120;
    return config;
}
