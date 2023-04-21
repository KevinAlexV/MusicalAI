// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MusicalAIGameMode.generated.h"

UCLASS(minimalapi)
class AMusicalAIGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMusicalAIGameMode();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<APawn> Default2DPawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<APawn> DefaultVRPawn;
};



