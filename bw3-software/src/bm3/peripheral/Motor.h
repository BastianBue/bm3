#pragma once

#include "bm3/peripheral/AbstractPeripheral.h"
#include "../../../include/utility/pwm/PwmPin.h"
#include "../../../include/utility/pwm/PwmSink.h"

using bm3::peripheral::AbstractPeripheral;

namespace bm3 { namespace peripheral {
    class Motor final : public AbstractPeripheral {
    public:
        Motor(PwmPin* pinA, PwmPin* pinB, PwmSink* sink, const char* descriptor);
        void forward(int speed) const; // speed: 0-100
        void backward(int speed) const; // speed: 0-100
        void stop() const;
        void setup() override;
    private:
        PwmPin* pinA;
        PwmPin* pinB;
        PwmSink* sink;
        const char* descriptor;
    };
}}
