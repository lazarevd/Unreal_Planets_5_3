 // Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Engine/Engine.h"
#include "GameFramework/InputSettings.h"


float kVec = 100.0;
float rotSpeed = 0.5;


void AMyPlayerController::UpdateRotation(float DeltaTime) {
	FRotator DeltaRot(RotationInput);
	//FRotator ViewRotation = GetControlRotation();

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(
	//	TEXT("RotationInput: pitch=%f, yaw=%f, roll=%f"), RotationInput.Pitch, RotationInput.Yaw, RotationInput.Roll));
	FlushPersistentDebugLines(GetWorld());
	//ViewRotation += DeltaRot;//from PlayerCameraManager ProcessViewRotation


	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(
		TEXT("ViewRotation: pitch=%3.1f, yaw=%3.1f, roll=%3.1f"), ViewRotation.Pitch, ViewRotation.Yaw, ViewRotation.Roll));

	//FlyRotationBasis = ViewRotation.Vector();


	FrontVec = FrontVec.RotateAngleAxis(DeltaRot.Pitch * rotSpeed, RightVec);
	RightVec = RightVec.RotateAngleAxis(-DeltaRot.Roll * rotSpeed, FrontVec);
	UpVec = FVector::CrossProduct(FrontVec, RightVec);

	DrawDebugLine(GetWorld(), FVector(0, 0, 0), FrontVec * kVec, FColor::Red, true, -1, 0, 10);
	DrawDebugLine(GetWorld(), FVector(0, 0, 0), RightVec * kVec, FColor::Green, true, -1, 0, 10);
	DrawDebugLine(GetWorld(), FVector(0, 0, 0), UpVec * kVec, FColor::Blue, true, -1, 0, 10);


	ViewRotation = FRotationMatrix::MakeFromXY(FrontVec, RightVec).Rotator();

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(
		TEXT("FrontVec: x=%3.1f, y=%3.1f, z=%3.1f"), FrontVec.X, FrontVec.Y, FrontVec.Z));

	//AActor* ViewTarget = GetViewTarget();

	DeltaRot = FRotator::ZeroRotator;
	//SetControlRotation(FRotator(-60, -30, 0));
	SetControlRotation(ViewRotation);

	/*
	APawn* const P = GetPawnOrSpectator();
	if (P)
	{
		P->FaceRotation(ViewRotation, DeltaTime);
	}*/
	}

/*
	void AMyPlayerController::AddRollInput(float Val)
	{
		
		FString pcm = PlayerCameraManager.GetFullName();
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(
			TEXT("PlayerCameraManager: %s"), *pcm));
		RotationInput.Roll +=  Val;
		FRotator rot = GetControlRotation();
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(
			TEXT("GetControlRotation: pitch=%f, yaw=%f, roll=%f"), rot.Pitch, rot.Yaw, rot.Roll));

		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("RollInput = %f"), Val));

	}*/

