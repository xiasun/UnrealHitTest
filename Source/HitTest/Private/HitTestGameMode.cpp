// Fill out your copyright notice in the Description page of Project Settings.


#include "HitTestGameMode.h"

#include "HitTestPlayerController.h"
#include "RuntimeMeshActor.h"
#include "Engine/World.h"

void AHitTestGameMode::StartPlay()
{
	Super::StartPlay();
	
	m_World = GetWorld();

	if (m_World == nullptr || !m_World->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Warning, TEXT("sx: StartPlay failed"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("sx: StartPlay succeeded"));
	
	FActorSpawnParameters SpawnParams;
	
	ARuntimeMeshActor* Actor1 = GetWorld()->SpawnActor<ARuntimeMeshActor>(SpawnParams);
	Actor1->CreateCube(100);
	Actor1->SetActorLocationAndRotation(FVector(0.0f, 0.0f, -150.0f), FRotator(0.0f, 0.0f, 0.0f));
	Actor1->SetActorScale3D(FVector(1, 1, 1));
	
	ARuntimeMeshActor* Actor2 = GetWorld()->SpawnActor<ARuntimeMeshActor>(SpawnParams);
	Actor2->CreateCube(1);
	Actor2->SetActorLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Actor2->SetActorScale3D(FVector(100, 100, 100));
	
	ARuntimeMeshActor* Actor3 = GetWorld()->SpawnActor<ARuntimeMeshActor>(SpawnParams);
	Actor3->CreateCube(0.005);
	Actor3->SetActorLocationAndRotation(FVector(0.0f, 0.0f, 150.0f), FRotator(0.0f, 0.0f, 0.0f));
	Actor3->SetActorScale3D(FVector(20000, 20000, 20000));
}

void AHitTestGameMode::HitTest()
{
	UE_LOG(LogTemp, Warning, TEXT("sx: HitTest"));

	if (m_World == nullptr || !m_World->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Warning, TEXT("sx: HitTest failed, no valid UWorld instance"));
		return;
	}

	APlayerController* Ctrl = m_World->GetFirstPlayerController();
	AHitTestPlayerController* HitCtrl = Cast<AHitTestPlayerController>(Ctrl);

	if (HitCtrl != nullptr || HitCtrl->IsValidLowLevel())
	{
		HitCtrl->HitTest(m_World);
	}
}
