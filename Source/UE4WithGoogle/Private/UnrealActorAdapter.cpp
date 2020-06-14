#include "UnrealActorAdapter.h"

UnrealActorAdapter::UnrealActorAdapter(AActor& actor) :
    mActor(actor)
{}
 
void UnrealActorAdapter::SetActorLocation(FVector location) 
{
    mActor.SetActorLocation(location);
}
 
FVector UnrealActorAdapter::GetActorLocation() 
{
    return mActor.GetActorLocation();
}