#include <Arduino.h>
#include "bm3/peripheral/Motor.h"
#include "bm3/config/RemoteXYConfig.h"
#include "esp_task_wdt.h"
#include  "bm3/input/InputInterpreterFactory.h"
#include  "bm3/state/State.h"
#include "config/PWMInit.h"
#include "bm3/config/PwmPin.h"
#include "bm3/config/PwmSink.h"

using bm3::peripheral::Motor;
using bm3::input::InputInterpreterFactory;
using bm3::input::InputInterpreter;
using bm3::state::State;

PwmSink pwmSink;

PwmPin rightPwmA(5);
PwmPin rightPwmB(4);
PwmPin leftPwmA(3);
PwmPin leftPwmB(2);

Motor leftMotor(&leftPwmA, &leftPwmB, &pwmSink);
Motor rightMotor(&rightPwmA, &rightPwmB, &pwmSink);

ReflectanceSensor leftSensor(1);
ReflectanceSensor rightSensor(0);

void setup()
{
    RemoteXY_Init();
    Serial.begin(9600);

    PWM_init();

    // pwm pins are setup by the motor class
    leftMotor.setup();
    rightMotor.setup();
}

void loop()
{
    RemoteXY_Handler();

    RemoteXY_delay(20);
    leftSensor.update();
    rightSensor.update();

    if (RemoteXY.is_connected && RemoteXY.is_on)
    {
        InputInterpreter* inputInterpreter = InputInterpreterFactory::createInterpreter(
            State::DEFAULT_STATE, &leftMotor, &rightMotor);
        inputInterpreter->interpretInput(RemoteXY.vertical_slider, RemoteXY.horizontal_slider);
        pwmSink.flush(); // Synchronize all PWM updates
    }

    esp_task_wdt_reset(); // Pet the Dog
}
