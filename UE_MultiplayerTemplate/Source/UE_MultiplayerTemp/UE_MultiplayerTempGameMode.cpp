// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_MultiplayerTempGameMode.h"
#include "UE_MultiplayerTempCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE_MultiplayerTempGameMode::AUE_MultiplayerTempGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
