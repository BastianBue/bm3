#include <Arduino.h>
#include "bm3/peripheral/Motor.h"
#include "bm3/config/RemoteXYConfig.h"
#include "esp_task_wdt.h"
#include  "bm3/input/InputInterpreterFactory.h"
#include  "bm3/state/State.h"
#include "config/PWMInit.h"
#include "bm3/config/PwmPin.h"

using bm3::peripheral::Motor;
using bm3::input::InputInterpreterFactory;
using bm3::input::InputInterpreter;
using bm3::state::State;

PwmPin leftPwmA(0);
PwmPin leftPwmB(1);
PwmPin rightPwmA(2);
PwmPin rightPwmB(3);

Motor leftMotor(&leftPwmA, &leftPwmB);
Motor rightMotor(&rightPwmA, &rightPwmB);

void setup()
{
    RemoteXY_Init();
    Serial.begin(9600);

    PWM_init();

    leftPwmA.setup();
    leftPwmB.setup();
    rightPwmA.setup();
    rightPwmB.setup();

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
