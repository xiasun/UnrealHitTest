// Fill out your copyright notice in the Description page of Project Settings.


#include "HitTestPlayerController.h"

void AHitTestPlayerController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
}


void AHitTestPlayerController::HitTest(UWorld* world)
{
	FVector mousePos, mouseDir;
	DeprojectMousePositionToWorld(mousePos, mouseDir);
	float maxDist = 1.0e9;
	
	FHitResult hitResult;
	bool hit = world->LineTraceSingleByChannel(hitResult, mousePos, mousePos + mouseDir * maxDist, ECollisionChannel::ECC_Visibility); 
	AActor* hitActor = hitResult.GetActor();
	
	if (hit && hitActor != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("sx: HitTest result %s"), *hitActor->GetActorLabel());
	}
}
