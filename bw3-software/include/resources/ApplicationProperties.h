#pragma once
#include <WString.h>

struct ApplicationProperties
{
    int someVar;
    String anotherVar;
};

ApplicationProperties loadProfileConfig();
