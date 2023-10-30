// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CPP_CONTROL_5_3_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	UPROPERTY()
	FVector FlyRotationBasis;
	UPROPERTY()
	FRotator ViewRotation;



public:
	// Sets default values for this character's properties
	//virtual void AddRollInput(float Val) override;
	FVector FrontVec = FVector(1, 0, 0);
	FVector RightVec = FVector(0, 1, 0);
	FVector UpVec = FVector(0, 0, 1);
	virtual void UpdateRotation(float DeltaTime);
	
};
