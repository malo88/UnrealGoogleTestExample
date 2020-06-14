// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FloatingActor.generated.h"

class UnrealMathAdapter;
class UnrealActorAdapter;
class CFloatingActor;

UCLASS()
class UE4WITHGOOGLE_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
private:    
    TSharedPtr<UnrealMathAdapter> mMathAdapter;
    TSharedPtr<UnrealActorAdapter> mActorAdapter;
    TSharedPtr<CFloatingActor> mCFloatingActor;
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
