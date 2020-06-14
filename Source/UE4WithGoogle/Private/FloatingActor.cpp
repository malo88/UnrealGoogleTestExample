#include "FloatingActor.h"
//#include "GameFramework/Actor.h"
#include "ExampleGameCore/Public/CFloatingActor.h"
#include "UnrealActorAdapter.h"
#include "UnrealMathAdapter.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
    mMathAdapter = MakeShareable(new UnrealMathAdapter());
    mActorAdapter = MakeShareable(new UnrealActorAdapter(*this));
    mCFloatingActor = MakeShareable(new CFloatingActor(*mActorAdapter, *mMathAdapter));
 
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}
 
// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
    Super::BeginPlay();
}
 
// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
 
    mCFloatingActor->Tick(DeltaTime);
}