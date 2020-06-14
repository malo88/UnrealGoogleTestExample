#pragma once

#include "ExampleGameCore/Public/IUnrealActor.h"
#include "ExampleGameCore/Public/IUnrealMath.h"

class EXAMPLEGAMECORE_API CFloatingActor
{
private:
    IUnrealActor& mActor;
    IUnrealMath& mMath;
    float mRunningTime;

public:
    CFloatingActor(IUnrealActor& actor, IUnrealMath& math);
    void Tick(float DeltaTime);
};