#pragma once
 
#include "CoreMinimal.h"
#include "CoreUObject.h"
#include "ExampleGameCore/Public/IUnrealActor.h"
 
class AActor;
 
class UnrealActorAdapter : public IUnrealActor 
{
private:
    AActor& mActor;
	
public:
    UnrealActorAdapter(AActor& actor);
    void SetActorLocation(FVector location) override;
    FVector GetActorLocation() override;
};