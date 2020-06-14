#pragma once

#include "CoreMinimal.h"

class IUnrealActor 
{
public:
    virtual ~IUnrealActor() = default;
    virtual void SetActorLocation(FVector location) = 0;
    virtual FVector GetActorLocation() = 0;
};