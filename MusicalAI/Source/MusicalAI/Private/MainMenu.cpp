// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"

AMainMenu::AMainMenu()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/MusicAI_GameMode/Blueprints/BP_ThirdPersonSprite"));

	/*if(FPaths::FileExists("F:\\Workspace\\Github\\MusicalAI\\MusicalAI\\Content\\ThirdPerson\\Blueprints"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("File exists"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Does not exist.."));
	}

	TArray<FString> FileNames;

	/JoyFileIO_GetFiles(FileNames, "F:\\Workspace\\Github\\MusicalAI\\MusicalAI\\Content\\ThirdPerson\\Blueprints", "");

	for (FString name : FileNames)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, name);

	}*/

	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

