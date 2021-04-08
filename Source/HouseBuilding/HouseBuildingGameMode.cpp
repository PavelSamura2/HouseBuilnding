// Copyright Epic Games, Inc. All Rights Reserved.

#include "HouseBuildingGameMode.h"
#include "HouseBuildingCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHouseBuildingGameMode::AHouseBuildingGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
