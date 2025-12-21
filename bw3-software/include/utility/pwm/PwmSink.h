#pragma once

#include <vector>
#include <algorithm>
#include <random>
#include "PwmPin.h"
#include "utility/Log.h"

class PwmSink
{
public:
    struct Entry
    {
        PwmPin* pin;
        int value;
    };

    void set(PwmPin* pin, int value)
    {
        for (auto& entry : entries_)
        {
            if (entry.pin == pin)
            {
                entry.value = value;
                return;
            }
        }
        entries_.push_back({pin, value});
    }

    void flush()
    {
        // Randomize the order of entries before flushing
        static std::random_device rd;
        static std::mt19937 g(rd());

        for (auto& entry : entries_)
        {
            if (entry.pin)
            {
                LOG("Writing analog value: " +String(entry.value)+ + " To pin: "+ String(entry.pin->pin_number));
                entry.pin->analogWrite(entry.value);
            }
        }
        entries_.clear();
    }

private:
    std::vector<Entry> entries_;
};
