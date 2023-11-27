// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HitTestPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class HITTEST_API AHitTestPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	
protected:
	
public:

	virtual void BeginPlay() override;

	void HitTest(UWorld* world);
	
protected:
	
};
