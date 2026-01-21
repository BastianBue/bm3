#pragma once

struct ApplicationProperties
{
    float tiltPercentage;
    float rotationPercentage;
    int motorMinimumThreshold;
    bool disalbeStateMachine;
};

inline ApplicationProperties loadProfileConfig()
{
    ApplicationProperties config;
    config.tiltPercentage = 0.93f;
    config.rotationPercentage = 0.60f;
    config.motorMinimumThreshold = 130;
    config.disalbeStateMachine = false;
    return config;
}
