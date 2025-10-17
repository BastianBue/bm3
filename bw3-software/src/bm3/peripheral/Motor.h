#pragma once

#include "bm3/peripheral/AbstractPeripheral.h"

using bm3::peripheral::AbstractPeripheral;

namespace bm3 { namespace peripheral {
    class Motor final : public AbstractPeripheral {
    public:
        Motor(int pinA, int pinB);
        void forward(int speed) const; // speed: 0-100
        void backward(int speed) const; // speed: 0-100
        void stop() const;
        void setup() override;
    private:
        int pinA;
        int pinB;
    };
}}
