// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "RuntimeMeshActor.generated.h"

UCLASS()
class HITTEST_API ARuntimeMeshActor : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	UProceduralMeshComponent* ProceduralMesh;

protected:

public:
	// Sets default values for this actor's properties
	ARuntimeMeshActor();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void CreateCube(float Length);

protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
