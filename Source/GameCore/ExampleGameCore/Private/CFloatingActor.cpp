#include "CFloatingActor.h"

CFloatingActor::CFloatingActor(IUnrealActor& actor, IUnrealMath& math) :
    mActor(actor),
    mMath(math),
    mRunningTime(0)
{
}

void CFloatingActor::Tick(float DeltaTime)
{
    FVector NewLocation = mActor.GetActorLocation();
    float DeltaHeight = (mMath.Sin(mRunningTime + DeltaTime) - mMath.Sin(mRunningTime));
    NewLocation.Z += DeltaHeight * 20.0f;
    mRunningTime += DeltaTime;
    mActor.SetActorLocation(NewLocation);
}