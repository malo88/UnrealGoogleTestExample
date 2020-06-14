#pragma once
 
#include "ExampleGameCore/Public/IUnrealMath.h"
 
class UnrealMathAdapter : public IUnrealMath
{
public:
    float Sin(float Value) override;
};