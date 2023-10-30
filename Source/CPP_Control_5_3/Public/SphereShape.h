// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "SphereShape.generated.h"

UCLASS()
class CPP_CONTROL_5_3_API ASphereShape : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASphereShape();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MeshParameters")
	FVector PolySize = FVector(100.f, 100.f, 100.f);

protected:
	// Called when the game starts or when spawned
	UPROPERTY(VisibleAnywhere)
	USceneComponent* ThisScene;
	UPROPERTY(VisibleAnywhere)
	UProceduralMeshComponent* ThisMesh;

	virtual void PostActorCreated() override;
	virtual void PostLoad() override;
	void GenerateMesh();

private:
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector> Normals;
	TArray<FProcMeshTangent>Tangents;
	TArray<FVector2D>UVs;
	TArray<FLinearColor>Colors;


	void AddSquareMesh(FVector normal, int32 resolution, int32 planeNumber, FProcMeshTangent Tangent);

	FVector PointOnCurveToPointOnSphere(FVector p);

};
