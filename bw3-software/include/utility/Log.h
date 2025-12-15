#pragma once
#include <Arduino.h>

#ifdef PROFILE_DEVELOPMENT
#define LOG(msg) Serial.print(msg)
#else
#define LOG(msg)
#endif
