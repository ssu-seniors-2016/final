// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine.h"
#include "GameFramework/GameUserSettings.h"
#include "GraphicSettingsLibrary.generated.h"

/**
*
*/


UCLASS()
class SENIORPROJECT_API UGraphicSettingsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UGraphicSettingsLibrary();
	~UGraphicSettingsLibrary();
	UFUNCTION(BlueprintCallable, Category = "Graphic Settings")
		static void SetShadows(int32 value);
	UFUNCTION(BlueprintCallable, Category = "Graphic Settings")
		static void SetPostProcesses(int32 value);
	UFUNCTION(BlueprintCallable, Category = "Graphic Settings")
		static void SetAntiAliasing(int32 value);
	UFUNCTION(BlueprintCallable, Category = "Graphic Settings")
		static void SetEffects(int32 value);
	UFUNCTION(BlueprintCallable, Category = "Graphic Settings")
		static void SetResolution(int32 value);
	UFUNCTION(BlueprintCallable, Category = "Graphic Settings")
		static void SetTexutres(int32 value);
	UFUNCTION(BlueprintCallable, Category = "Graphic Settings")
		static void SetViewDistance(float value);
	UFUNCTION(BlueprintCallable, Category = "Graphic Settings")
		static void ApplySettings();
};
