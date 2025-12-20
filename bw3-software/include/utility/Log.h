#pragma once
#include <Arduino.h>

#ifdef PROFILE_DEVELOPMENT
#define LOG(msg) Serial.println(String("{\"msg\":\"") + String(msg) + "\",\"file\":\"file://" + String(GIT_ROOT_PATH) + "/bw3-software/" + String(__FILE__) + "\",\"line\":" + String(__LINE__) + ",\"date\":\"" + String(__DATE__) + "\",\"time\":\"" + String(__TIME__) + "\"}")
#else
#define LOG(msg)
#endif
