// Copyright Epic Games, Inc. All Rights Reserved.

#include "BoardGamesGameMode.h"
#include "BoardGamesCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABoardGamesGameMode::ABoardGamesGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
