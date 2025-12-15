#pragma once

// Profile selection based on build flags

#if defined(PROFILE_DEVELOPMENT)
constexpr int SOME_VAR = 42;
constexpr const char* ANOTHER_VAR = "default";
#endif
