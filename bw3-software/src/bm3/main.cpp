#include <Arduino.h>

#include "bm3/peripheral/Motor.h"
#include "bm3/config/RemoteXYConfig.h"
#include "esp_task_wdt.h"
#include  "bm3/input/InputInterpreterFactory.h"
#include  "bm3/state/State.h"
#include "config/PWMInit.h"
#include "bm3/config/PwmPin.h"
#include "bm3/config/PwmSink.h"
#include "state/StateMachine.h"
#include "../../include/resources/ApplicationProperties.h"

using bm3::peripheral::Motor;
using bm3::input::InputInterpreterFactory;
using bm3::input::InputInterpreter;
using bm3::state::State;
using bm3::state::StateMachine;

ApplicationProperties config = loadProfileConfig();

PwmSink pwmSink;

PwmPin rightPwmA(5);
PwmPin rightPwmB(4);
PwmPin leftPwmA(3);
PwmPin leftPwmB(2);

Motor leftMotor(&leftPwmA, &leftPwmB, &pwmSink);
Motor rightMotor(&rightPwmA, &rightPwmB, &pwmSink);

ReflectanceSensor leftSensor(1);
ReflectanceSensor rightSensor(0);

StateMachine stateMachine(State::DEFAULT_STATE, leftSensor, rightSensor);

void setup()
{
    Serial.begin(9600);

    Serial.print("Loaded profile config: someVar=");
    Serial.print(config.someVar);
    Serial.print(", anotherVar=");
    Serial.println(config.anotherVar);

    PWM_init();

    // pwm pins are setup by the motor class
    leftMotor.setup();
    rightMotor.setup();

    leftSensor.setup();
    rightSensor.setup();
}

void loop()
{
    RemoteXY_delay(1000);
    RemoteXY_Handler();

    if (RemoteXY.is_connected && RemoteXY.is_on)
    {
        stateMachine.update();
        InputInterpreter* inputInterpreter = InputInterpreterFactory::createInterpreter(
            stateMachine.getState(), &leftMotor, &rightMotor);
        inputInterpreter->interpretInput(RemoteXY.vertical_slider, RemoteXY.horizontal_slider);
    }
    else
    {
        leftMotor.stop();
        rightMotor.stop();
    }

    pwmSink.flush(); // Synchronize all PWM updates

    esp_task_wdt_reset(); // Pet the Dog
}
