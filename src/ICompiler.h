#pragma once
#include <iostream>

class ICompiler
{
public:
    virtual void IncrementPointer() = 0;
    virtual void DecrementPointer() = 0;
    virtual void IncrementData() = 0;
    virtual void DecrementData() = 0;
    virtual void ReadData() = 0;
    virtual void JumpForward(int src, int dest) = 0;
    virtual void JumpBackward(int src, int dest) = 0;
};