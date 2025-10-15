#pragma once

namespace bm3 { namespace hardware {

class AbstractPeripheral {
public:
    virtual void setup() = 0;
    virtual ~AbstractPeripheral() {}
};

}}
