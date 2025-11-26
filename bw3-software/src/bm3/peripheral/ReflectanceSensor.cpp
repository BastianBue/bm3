#include "bm3/peripheral/ReflectanceSensor.h"

#include <esp32-hal-adc.h>
#include <HardwareSerial.h>

namespace bm3
{
    namespace peripheral
    {
        ReflectanceSensor::ReflectanceSensor(const int pin)
        {
            readPinNumber = pin;
            reflectanceValue = analogRead(readPinNumber);
        }

        void ReflectanceSensor::update()
        {
            reflectanceValue = analogRead(readPinNumber);
            Serial.println("ReflectanceSensor::update " + String(reflectanceValue) + " isDark = " + this->isDark() + " isLight = " + this->isLight());
        }

        bool ReflectanceSensor::isDark() const
        {
            return reflectanceValue < 800;
        }

        bool ReflectanceSensor::isLight() const
        {
            return reflectanceValue >= 800;
        }

        void ReflectanceSensor::setup()
        {
            Serial.println("ReflectanceSensor::setup");
            // no need for pin mode as it is alread correct
        }
    }
}
