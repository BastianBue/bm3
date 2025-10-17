#pragma once

namespace bm3 { namespace peripheral {

class AbstractPeripheral {
public:
    virtual void setup() = 0;
    virtual ~AbstractPeripheral() {}
};

}}
