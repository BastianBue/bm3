#pragma once
#include "AbstractPeripheral.h"

namespace bm3 { namespace hardware {
    class Motor : public AbstractPeripheral {
    public:
        Motor(int pinA, int pinB);
        void forward(int speed); // speed: 0-100
        void backward(int speed); // speed: 0-100
        void stop();
        void setup() override;
    private:
        int pinA;
        int pinB;
    };
}}
