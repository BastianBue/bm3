#pragma once
#include <WString.h>

#include "ApplicationProperties.Development.h"
#include "ApplicationProperties.Productions.h"

struct ApplicationProperties
{
    int someVar;
    String anotherVar;
};

inline ApplicationProperties loadProfileConfig() {
    ApplicationProperties config;
    config.someVar = SOME_VAR;
    config.anotherVar = ANOTHER_VAR;
    return config;
}
