#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wmissing-variable-declarations"

#define REMOTEXY_MODE__ESP32CORE_BLE
#define REMOTEXY_BLUETOOTH_NAME "RemoteXY"

#include <BLEDevice.h>
#include <RemoteXY.h>

#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 62 bytes
  { 255,4,0,0,0,55,0,19,0,0,0,0,24,1,106,200,1,1,4,0,
  2,64,6,33,7,0,2,26,31,31,79,78,0,79,70,70,0,4,37,72,
  62,11,160,2,26,4,19,42,12,69,32,2,26,1,55,96,27,27,0,2,
  31,0 };

struct {
    uint8_t switch_02; // =1 if switch ON and =0 if OFF, from 0 to 1
    int8_t slider_01; // from -100 to 100
    int8_t slider_02; // from -100 to 100
    uint8_t button_01; // =1 if button pressed, else =0, from 0 to 1
    uint8_t connect_flag;  // =1 if wire connected, else =0
} RemoteXY;
#pragma pack(pop)

#pragma clang diagnostic pop
