#pragma once
#include <Arduino.h>

#ifdef PROFILE_DEVELOPMENT
#define LOG(msg) Serial.println("file://" + String(__FILE__) + ":" + String(__LINE__) + " " + String("{\"msg\":\"" + String(msg) + "\",\"file\":\"" + String(__FILE__) + "\",\"line\":" + String(__LINE__) + ",\"date\":\"" + String(__DATE__) + "\",\"time\":\"" + String(__TIME__) + "\"}"))
#else
#define LOG(msg)
#endif
