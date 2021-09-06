#pragma once

class IInterpreter
{
public:
    virtual void IncrementPointer() = 0;
    virtual void DecrementPointer() = 0;
    virtual void IncrementData() = 0;
    virtual void DecrementData() = 0;
    virtual void WriteData() = 0;
    virtual bool TestZero() const = 0;
};