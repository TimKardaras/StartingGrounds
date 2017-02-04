// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "StartingGroundsHUD.generated.h"

UCLASS()
class AStartingGroundsHUD : public AHUD
{
	GENERATED_BODY()

public:
	AStartingGroundsHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

