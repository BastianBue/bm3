#pragma once

#include "bm3/peripheral/AbstractPeripheral.h"
#include "bm3/config/PwmPin.h"
#include "bm3/config/PwmSink.h"

using bm3::peripheral::AbstractPeripheral;

namespace bm3 { namespace peripheral {
    class Motor final : public AbstractPeripheral {
    public:
        Motor(PwmPin* pinA, PwmPin* pinB, PwmSink* sink);
        void forward(int speed) const; // speed: 0-100
        void backward(int speed) const; // speed: 0-100
        void stop() const;
        void setup() override;
    private:
        PwmPin* pinA;
        PwmPin* pinB;
        PwmSink* sink;
    };
}}
