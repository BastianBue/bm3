#ifndef BM3_HARDWARE_ABSTRACTPERIPHERAL_H
#define BM3_HARDWARE_ABSTRACTPERIPHERAL_H
#pragma once

namespace bm3 { namespace hardware {

class AbstractPeripheral {
public:
    virtual void setup() = 0;
    virtual ~AbstractPeripheral() {}
};

}}

#endif // BM3_HARDWARE_ABSTRACTPERIPHERAL_H
