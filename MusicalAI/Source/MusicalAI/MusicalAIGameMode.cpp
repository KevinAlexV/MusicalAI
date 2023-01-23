// Copyright Epic Games, Inc. All Rights Reserved.

#include "MusicalAIGameMode.h"
#include "MusicalAICharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Sound/SoundBase.h"

AMusicalAIGameMode::AMusicalAIGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
