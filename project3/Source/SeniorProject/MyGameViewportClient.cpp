// Fill out your copyright notice in the Description page of Project Settings.

#include "SeniorProject.h"
#include "MyGameViewportClient.h"

TOptional<bool> UMyGameViewportClient::QueryShowFocus(const EFocusCause InFocusCause) const
{
	return false;
}

bool UMyGameViewportClient::InputKey
(
FViewport* Viewport,
int32 ControllerId,
FKey Key,
EInputEvent Event,
float AmountDepressed,
bool bGamepad
) 
{
	AMyGameMode* game = Cast<AMyGameMode>(GetWorld()->GetAuthGameMode());
	if (game)
	{
		if (Key.GetDisplayName().ToString() == "Gamepad Special Right")
		{
			game->TryAddNewPlayer(ControllerId);
		}
		else if (Key.GetDisplayName().ToString() == "Gamepad Face Button Right")
		{
			game->TryRemovePlayer(ControllerId);
		}
		/*if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, Key.GetDisplayName().ToString());
		}*/

	}
	return Super::InputKey(Viewport, ControllerId, Key, Event, AmountDepressed, bGamepad);
}



