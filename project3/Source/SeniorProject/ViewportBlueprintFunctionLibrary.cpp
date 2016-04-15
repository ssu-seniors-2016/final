// Fill out your copyright notice in the Description page of Project Settings.

#include "SeniorProject.h"
#include "ViewportBlueprintFunctionLibrary.h"
#include "MyGameViewportClient.h"

void UViewportBlueprintFunctionLibrary::DisableSplitScreen(UObject* WorldContextObject, bool Disable)
{
	UMyGameViewportClient* gvc = Cast<UMyGameViewportClient>(WorldContextObject->GetWorld()->GetGameViewport());
	gvc->SetDisableSplitscreenOverride(Disable);
}


void UViewportBlueprintFunctionLibrary::SetSplitScreenCount(UObject* WorldContextObject, int32 PlayerCount)
{
	UMyGameViewportClient* gvc = Cast<UMyGameViewportClient>(WorldContextObject->GetWorld()->GetGameViewport());
	gvc->MaxSplitscreenPlayers = PlayerCount;
	gvc->UpdateActiveSplitscreenType();
}



