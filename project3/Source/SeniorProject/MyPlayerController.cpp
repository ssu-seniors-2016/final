// Fill out your copyright notice in the Description page of Project Settings.

#include "SeniorProject.h"
#include "MyPlayerController.h"

AMyPlayerController::AMyPlayerController()
{
	this->bAutoManageActiveCameraTarget = false;
}


void AMyPlayerController::DisableCameraManagement()
{
	this->bAutoManageActiveCameraTarget = false;
}

