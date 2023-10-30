// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "MyPawnMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class CPP_CONTROL_5_3_API UMyPawnMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()

protected:
	
public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
