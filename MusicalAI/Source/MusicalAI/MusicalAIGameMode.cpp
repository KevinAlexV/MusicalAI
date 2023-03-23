// Copyright Epic Games, Inc. All Rights Reserved.

#include "MusicalAIGameMode.h"
#include "MusicalAICharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Sound/SoundBase.h"
#include "Projectile.h"

/** Obtain all files in a provided directory, with optional extension filter. All files are returned if Ext is left blank. Returns false if operation could not occur. */
//UFUNCTION(BlueprintPure, Category = "VictoryBPLibrary|File IO")
//static bool JoyFileIO_GetFiles(TArray<FString>& Files, FString RootFolderFullPath, FString Ext);

bool JoyFileIO_GetFiles(TArray<FString>& Files, FString RootFolderFullPath, FString Ext)
{
	if (RootFolderFullPath.Len() < 1) return false;

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Searching files.."));
	FPaths::NormalizeDirectoryName(RootFolderFullPath);

	IFileManager& FileManager = IFileManager::Get();

	if (Ext == "")
	{
		Ext = "*.*";
	}
	else
	{
		Ext = (Ext.Left(1) == ".") ? "*" + Ext : "*." + Ext;
	}

	FString FinalPath = RootFolderFullPath + "/" + Ext;
	FileManager.FindFiles(Files, *FinalPath, true, false);
	return true;
}

AMusicalAIGameMode::AMusicalAIGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/MusicAI_GameMode/BP_Character"));///Game/MusicAI_GameMode/Blueprints/BP_ThirdPersonCharacter

	static ConstructorHelpers::FClassFinder<AProjectile> PlayerProjectileA(TEXT("/Game/Characters/CharacterProps/MyProjectile"));

	UE_LOG(LogTemp, Log, TEXT("[MusicalAIGameMode] ProjectileClass seraching..."));

	if (PlayerProjectileA.Class != NULL)
	{
		//ProjectileClass = PlayerProjectileA.Class;
		UE_LOG(LogTemp, Warning, TEXT("[MusicalAIGameMode] ProjectileClass found."));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[MusicalAIGameMode] ProjectileClass not found."));
		//UKismetSystemLibrary::QuitGame(GetWorld(), 0, EQuitPreference::Quit, true);
	}


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

	for (FString nadwme : FileNames) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, name);
	
	}*/

	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

