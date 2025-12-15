#include "../../include/resources/ApplicationProperties.h"
#include "resources/ApplicationProperties.Development.h"
#include "resources/ApplicationProperties.Productions.h"

ApplicationProperties loadProfileConfig() {
    ApplicationProperties config;
    config.someVar = SOME_VAR;
    config.anotherVar = ANOTHER_VAR;
    return config;
}
