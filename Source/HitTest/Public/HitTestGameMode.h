// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "HitTestGameMode.generated.h"

/**
 * 
 */
UCLASS()
class HITTEST_API AHitTestGameMode : public AGameMode
{
	GENERATED_BODY()

public:

protected:

	UWorld* m_World;

public:

	virtual void StartPlay() override;

	UFUNCTION(BlueprintCallable)
	void HitTest();

protected:
	
};
