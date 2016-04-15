// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SENIORPROJECT_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()

public:
		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "MyGameMode")
		void TryAddNewPlayer(int32 ControllerId);		
		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "MyGameMode")
		void TryRemovePlayer(int32 ControllerId);
};
