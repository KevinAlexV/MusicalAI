// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MusicalAI/MusicalAIGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMusicalAIGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	MUSICALAI_API UClass* Z_Construct_UClass_AMusicalAIGameMode();
	MUSICALAI_API UClass* Z_Construct_UClass_AMusicalAIGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_MusicalAI();
// End Cross Module References
	void AMusicalAIGameMode::StaticRegisterNativesAMusicalAIGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMusicalAIGameMode);
	UClass* Z_Construct_UClass_AMusicalAIGameMode_NoRegister()
	{
		return AMusicalAIGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AMusicalAIGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMusicalAIGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_MusicalAI,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMusicalAIGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "MusicalAIGameMode.h" },
		{ "ModuleRelativePath", "MusicalAIGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMusicalAIGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMusicalAIGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMusicalAIGameMode_Statics::ClassParams = {
		&AMusicalAIGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AMusicalAIGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMusicalAIGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMusicalAIGameMode()
	{
		if (!Z_Registration_Info_UClass_AMusicalAIGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMusicalAIGameMode.OuterSingleton, Z_Construct_UClass_AMusicalAIGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMusicalAIGameMode.OuterSingleton;
	}
	template<> MUSICALAI_API UClass* StaticClass<AMusicalAIGameMode>()
	{
		return AMusicalAIGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMusicalAIGameMode);
	AMusicalAIGameMode::~AMusicalAIGameMode() {}
	struct Z_CompiledInDeferFile_FID_MusicalAI_Source_MusicalAI_MusicalAIGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MusicalAI_Source_MusicalAI_MusicalAIGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMusicalAIGameMode, AMusicalAIGameMode::StaticClass, TEXT("AMusicalAIGameMode"), &Z_Registration_Info_UClass_AMusicalAIGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMusicalAIGameMode), 963733971U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MusicalAI_Source_MusicalAI_MusicalAIGameMode_h_648433463(TEXT("/Script/MusicalAI"),
		Z_CompiledInDeferFile_FID_MusicalAI_Source_MusicalAI_MusicalAIGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MusicalAI_Source_MusicalAI_MusicalAIGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
