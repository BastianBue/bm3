#pragma once
#include <esp_private/esp_wifi_types_private.h>

#include "AbstractPeripheral.h"

namespace bm3
{
    namespace peripheral
    {
        class ReflectanceSensor : public AbstractPeripheral
        {
        public:
            explicit ReflectanceSensor(int readPinNumber);
            void setup() override;
            bool isDark() const;
            bool isLight() const;
            void update();

        private:
            double reflectanceValue;
            int readPinNumber{};
        };
    }
}
