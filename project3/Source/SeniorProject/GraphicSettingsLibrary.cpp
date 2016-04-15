// Fill out your copyright notice in the Description page of Project Settings.

#include "SeniorProject.h"
#include "GraphicSettingsLibrary.h"

//UGameUserSettings* mSettings = GEngine->GameUserSettings;

UGraphicSettingsLibrary::UGraphicSettingsLibrary()
{
}

UGraphicSettingsLibrary::~UGraphicSettingsLibrary()
{
}

void UGraphicSettingsLibrary::SetShadows(int32 value) {
	if (value > 2)
		value = 2;
	else if (value < 0)
		value = 0;
	if(value == 0)
		value = 1;
	else if(value == 1)
		value = 2;
	else if(value == 2)
		value = 3;
	GEngine->GameUserSettings->ScalabilityQuality.ShadowQuality = value;
}

void UGraphicSettingsLibrary::SetPostProcesses(int32 value) {
	if (value > 2)
		value = 2;
	else if (value < 0)
		value = 0;
	if(value == 0)
		value = 1;
	else if(value == 1)
		value = 2;
	else if(value == 2)
		value = 3;
	GEngine->GameUserSettings->ScalabilityQuality.PostProcessQuality = value;
}

void UGraphicSettingsLibrary::SetAntiAliasing(int32 value) {
	if (value > 2)
		value = 2;
	else if (value < 0)
		value = 0;
	if(value == 0)
		value = 2;
	else if(value == 1)
		value = 4;
	else if(value == 2)
		value = 6;
	GEngine->GameUserSettings->ScalabilityQuality.AntiAliasingQuality = value;
}

void UGraphicSettingsLibrary::SetEffects(int32 value) {
	if (value > 2)
		value = 2;
	else if (value < 0)
		value = 0;
	if(value == 0)
		value = 1;
	else if(value == 1)
		value = 2;
	else if(value == 2)
		value = 3;
	GEngine->GameUserSettings->ScalabilityQuality.EffectsQuality = value;
}

void UGraphicSettingsLibrary::SetResolution(int32 value) {
	if (value > 2)
		value = 2;
	else if (value < 0)
		value = 0;
	if(value == 0)
		value = 10;
	else if(value == 1)
		value = 60;
	else if(value == 2)
		value = 100;
	GEngine->GameUserSettings->ScalabilityQuality.ResolutionQuality = value;
}

void UGraphicSettingsLibrary::SetTexutres(int32 value) {
	if (value > 2)
		value = 2;
	else if (value < 0)
		value = 0;
	if(value == 0)
		value = 1;
	else if(value == 1)
		value = 2;
	else if(value == 2)
		value = 3;
	GEngine->GameUserSettings->ScalabilityQuality.TextureQuality = value;
}

void UGraphicSettingsLibrary::SetViewDistance(float value) {
	if (value > 2)
		value = 2;
	else if (value < 0)
		value = 0;
	if(value == 0)
		value = 0.33;
	else if(value == 1)
		value = 0.66;
	else if(value == 2)
		value = 1;
	GEngine->GameUserSettings->ScalabilityQuality.ViewDistanceQuality = value;
}

void UGraphicSettingsLibrary::ApplySettings() {
	GEngine->GameUserSettings->ApplySettings();
}

