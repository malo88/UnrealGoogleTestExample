#pragma once

class IUnrealMath
{
public:
    virtual ~IUnrealMath() = default;
    virtual float Sin(float Value) = 0;
};