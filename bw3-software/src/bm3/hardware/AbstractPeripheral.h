#pragma once

namespace bm3 { namespace hardware {

class Peripheral {
public:
    virtual void setup() = 0;
    virtual ~Peripheral() {}
};

}}
