// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "StartingGrounds.h"
#include "StartingGroundsGameMode.h"
#include "StartingGroundsHUD.h"
#include "Player/FirstPersonCharacter.h"

AStartingGroundsGameMode::AStartingGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/Behaviour/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AStartingGroundsHUD::StaticClass();
}
