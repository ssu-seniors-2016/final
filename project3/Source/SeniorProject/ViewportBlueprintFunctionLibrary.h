// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ViewportBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SENIORPROJECT_API UViewportBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


	
public:
		UFUNCTION(BlueprintCallable, Category = "MyViewport")
		static void DisableSplitScreen(UObject* WorldContextObject, bool Disable);

		UFUNCTION(BlueprintCallable, Category = "MyViewport")
		static void SetSplitScreenCount(UObject* WorldContextObject, int32 PlayerCount);

};
