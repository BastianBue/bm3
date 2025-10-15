#define REMOTEXY_MODE__ESP32CORE_BLE

#include <RemoteXY.h>
#include <BLEDevice.h>

#include "hardware/Motor.h"
#include "core/RemoteXYConfig.h"

#define REMOTEXY_BLUETOOTH_NAME "RemoteXY"


bm3::hardware::Motor leftMotor(5, 6); // Example pins
bm3::hardware::Motor rightMotor(7, 8); // Example pins

void setup()
{
  RemoteXY_Init();
  Serial.begin(9600);

  leftMotor.setup();
  rightMotor.setup();
}

void loop()
{
  RemoteXY_Handler();
  Serial.println(RemoteXY.slider_01);
  Serial.println(RemoteXY.slider_02);
  Serial.println(RemoteXY.switch_02);
  Serial.println(RemoteXY.button_01);
}