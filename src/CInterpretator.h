#pragma once
#include <array>
#include <iostream>
#include "IInterpretator.h"
class CInterpreter : public IInterpreter
{
public:
    CInterpreter(size_t size = 30000)
        : _ptr(0)
    {
        array.fill(0);
    }

    virtual void IncrementPointer()
    {
        if (_ptr < array.size() - 1)
            _ptr++;
    }

    virtual void DecrementPointer()
    {
        if (_ptr > 0)
            _ptr--;
    }

    virtual void IncrementData()
    {
        array[_ptr]++;
    }

    virtual void DecrementData()
    {
        array[_ptr]--;
    }

    virtual void WriteData()
    {
        std::cout << array[_ptr];
    }

    virtual bool TestZero() const
    {
        return array[_ptr] == 0;
    }

protected:
    std::array<char,30000> array;
    size_t _ptr;
};