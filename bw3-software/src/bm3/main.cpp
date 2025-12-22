#include <Arduino.h>

#include "bm3/peripheral/Motor.h"
#include "utility/pwm/PWMInit.h"
#include "RemoteXYConfig.h"
#include "esp_task_wdt.h"
#include  "bm3/input/InputInterpreterFactory.h"
#include  "bm3/state/State.h"
#include "utility/pwm/PwmSink.h"
#include "utility/pwm/PwmPin.h"
#include "state/StateMachine.h"
#include "utility/Log.h"
#include "resources/ApplicationProperties.h"

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

Motor leftMotor(&leftPwmA, &leftPwmB, &pwmSink, "left motor", config);
Motor rightMotor(&rightPwmA, &rightPwmB, &pwmSink, "right motor", config);

ReflectanceSensor leftSensor(1);
ReflectanceSensor rightSensor(0);

StateMachine stateMachine(State::DEFAULT_STATE, leftSensor, rightSensor, config);

void setup()
{
    RemoteXY_Init();

    Serial.begin(9600);

    LOG("Loaded profile config: tiltPercentage=");
    LOG(config.tiltPercentage);
    LOG(", rotationPercentage=");
    LOG(config.rotationPercentage);
    LOG(", motorMinimumThreshold=");
    LOG(config.motorMinimumThreshold);

    PWM_init();

    // pwm pins are setup by the motor class
    leftMotor.setup();
    rightMotor.setup();

    leftSensor.setup();
    rightSensor.setup();
}

void loop()
{
    RemoteXY_Handler();

#ifdef PROFILE_DEVELOPMENT
    RemoteXY_delay(2000);
#endif


#ifdef PROFILE_PRODUCTION
    if (RemoteXY.is_connected && RemoteXY.is_on)
    {


#endif
    LOG("is connected: " + String(RemoteXY.is_connected) + "   is on: " + String(RemoteXY.is_on));
    stateMachine.update();
    InputInterpreter* inputInterpreter = InputInterpreterFactory::createInterpreter(
        stateMachine.getState(), &leftMotor, &rightMotor, config);
    inputInterpreter->interpretInput(RemoteXY.vertical_slider, RemoteXY.horizontal_slider);
#ifdef PROFILE_PRODUCTION
    }
    else
    {
        leftMotor.stop();
        rightMotor.stop();
    }
#endif
    pwmSink.flush(); // Synchronize all PWM updates

    esp_task_wdt_reset(); // Pet the Dog
}
