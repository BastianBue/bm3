#define REMOTEXY_MODE__ESP32CORE_BLE

#include <BLEDevice.h>
#include <RemoteXY.h>

#define REMOTEXY_BLUETOOTH_NAME "Motor"
#define REMOTEXY_ACCESS_PASSWORD "test"

#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 44 bytes
  { 255,2,0,0,0,37,0,18,0,0,0,31,1,106,200,1,1,2,0,4,
  45,1,20,159,48,2,26,2,38,174,44,22,0,2,26,31,31,79,78,0,
  79,70,70,0 };

struct {
  int8_t slider_01;
  uint8_t switch_01;
  uint8_t connect_flag;

} RemoteXY;
#pragma pack(pop)

int B_1 = 0;
int A_1 = 1;
int motor = RemoteXY.slider_01;
int power_switch = RemoteXY.switch_01;

void setup()
{
  RemoteXY_Init ();
  Serial.begin(9600);
}

void loop()
{
  RemoteXY_Handler ();
  Serial.println(motor);
  Serial.println(power_witch);
}
