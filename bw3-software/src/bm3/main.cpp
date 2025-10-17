#include <Arduino.h>
#include "bm3/peripheral/Motor.h"
#include "bm3/config/RemoteXYConfig.h"
#include "esp_task_wdt.h"
#include  "bm3/input/InputInterpreterFactory.h"
#include  "bm3/state/State.h"
#include "PWM.h"

using bm3::peripheral::Motor;
using bm3::input::InputInterpreterFactory;
using bm3::input::InputInterpreter;
using bm3::state::State;

Motor leftMotor(0, 1); // Example pins
Motor rightMotor(2, 3); // Example pins

void setup()
{
    RemoteXY_Init();
    Serial.begin(9600);

    PWM_init();

    leftMotor.setup();
    rightMotor.setup();
}

void loop()
{
    RemoteXY_Handler();
    InputInterpreter* inputInterpreter = InputInterpreterFactory::createInterpreter(State::DEFAULT_STATE, &leftMotor, &rightMotor);
    inputInterpreter->interpretInput(RemoteXY.vertical_slider, RemoteXY.horizontal_slider);
    esp_task_wdt_reset(); // Pet the Dog
}
