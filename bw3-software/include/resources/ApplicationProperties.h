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
    config.rotationPercentage = 0.2f;
    config.motorMinimumThreshold = 120;
    config.disalbeStateMachine = false;
    return config;
}
