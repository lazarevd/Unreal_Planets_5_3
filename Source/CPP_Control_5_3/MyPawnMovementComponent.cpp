// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPawnMovementComponent.h"
#include "InputExampleCharacter.h"




UMyPawnMovementComponent::UMyPawnMovementComponent() {

}


void UMyPawnMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    //Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
    // Make sure that everything is still valid, and that we are allowed to move.
    if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
    {
        return;
    }

    // Get (and then clear) the movement vector that we set in ACollidingPawn::Tick
    FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * 150.0f;
    FHitResult Hit;
    SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);

    FVector InputVector = ConsumeInputVector();
    CharacterOwnerP = Cast<AInputExampleCharacter>(PawnOwner);
    AController* Controller = CharacterOwnerP->Controller;
    FRotator MovementRotation(0, Controller->GetControlRotation().Yaw, 0);
    FVector Direction = MovementRotation.RotateVector(FVector::ForwardVector);


};