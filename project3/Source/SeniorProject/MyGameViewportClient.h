// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameViewportClient.h"
#include "MyGameMode.h"
#include "MyGameViewportClient.generated.h"


/**
 * 
 */
UCLASS()
class SENIORPROJECT_API UMyGameViewportClient : public UGameViewportClient
{
	GENERATED_BODY()

public:
	virtual TOptional<bool> QueryShowFocus(const EFocusCause InFocusCause) const override;

	bool InputKey
		(
		FViewport* Viewport,
		int32 ControllerId,
		FKey Key,
		EInputEvent Event,
		float AmountDepressed,
		bool bGamepad
		) override;
};
