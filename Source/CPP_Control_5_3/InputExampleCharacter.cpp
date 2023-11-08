    // Fill out your copyright notice in the Description page of Project Settings.

#include "InputExampleCharacter.h"
#include "MyInputConfigData.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include <EnhancedInputComponent.h>
#include "InputActionValue.h"
#include "MyPlayerController.h"
#include "MyPawnMovementComponent.h"





// Sets default values
AInputExampleCharacter::AInputExampleCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    // Create an instance of our movement component, and tell it to update the root.
    OurMovementComponent = CreateDefaultSubobject<UMyPawnMovementComponent>(TEXT("CustomMovementComponent"));
    OurMovementComponent->UpdatedComponent = RootComponent;

}

// Called when the game starts or when spawned
void AInputExampleCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInputExampleCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input

void AInputExampleCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
    // Get the player controller
    PlayerController = Cast<AMyPlayerController>(GetController());

    // Get the local player subsystem
    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
    // Clear out existing mapping, and add our mapping
    Subsystem->ClearAllMappings();
    Subsystem->AddMappingContext(InputMapping, 0);

    // Get the EnhancedInputComponent
    UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    // Bind the actions
    PEI->BindAction(InputActions->InputMove, ETriggerEvent::Triggered, this, &AInputExampleCharacter::Move);
    PEI->BindAction(InputActions->InputLook, ETriggerEvent::Triggered, this, &AInputExampleCharacter::Look);

}
void AInputExampleCharacter::Move(const FInputActionValue& Value)
{
    if (Controller != nullptr)
    {
        const FVector2D MoveValue = Value.Get<FVector2D>();
        //const FRotator MovementRotation(0, Controller->GetControlRotation().Yaw, 0);

        // Forward/Backward direction
        if (MoveValue.Y != 0.f)
        {
            // Get forward vector
           // const FVector Direction = MovementRotation.RotateVector(FVector::ForwardVector);
            
            //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(
            //    TEXT("FrontVec: x=%3.1f, y=%3.1f, z=%3.1f"), PlayerController->FrontVec.X, PlayerController->FrontVec.Y, PlayerController->FrontVec.Z));
            //PlayerController->FrontVec;
            AddMovementInput(PlayerController->FrontVec, MoveValue.Y);
        }

        // Right/Left direction
        if (MoveValue.X != 0.f)
        {
            // Get right vector
            //const FVector Direction = MovementRotation.RotateVector(FVector::RightVector);

            AddMovementInput(PlayerController->RightVec, MoveValue.X);
        }
    }
}

void AInputExampleCharacter::Test() {

}

void AInputExampleCharacter::Look(const FInputActionValue& Value)
{
    if (Controller != nullptr)
    {
        const FVector2D LookValue = Value.Get<FVector2D>();
        
        if (LookValue.X != 0.f)
        {
            AddControllerRollInput(LookValue.X);
        }

        if (LookValue.Y != 0.f)
        {
            AddControllerPitchInput(LookValue.Y);
        }
    }
}


UPawnMovementComponent* AInputExampleCharacter::GetMovementComponent() const
{
    return OurMovementComponent;
}