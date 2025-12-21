#pragma once

// Profile selection based on build flags

#if defined(PROFILE_DEVELOPMENT)
constexpr float TILT_PERCENTAGE = 0.93f;
constexpr float ROTATION_PERCENTAGE = 0.5f;
constexpr int MOTOR_MINIMUM_THRESHOLD = 120;
constexpr int MOTOR_MAXIMUM_THRESHOLD = 255;
#endif
