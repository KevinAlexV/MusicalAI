// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Projectile.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef MUSICALAI_Projectile_generated_h
#error "Projectile.generated.h already included, missing '#pragma once' in Projectile.h"
#endif
#define MUSICALAI_Projectile_generated_h

#define FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_SPARSE_DATA
#define FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOverlapBegin);


#define FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOverlapBegin);


#define FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_ACCESSORS
#define FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProjectile(); \
	friend struct Z_Construct_UClass_AProjectile_Statics; \
public: \
	DECLARE_CLASS(AProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MusicalAI"), NO_API) \
	DECLARE_SERIALIZER(AProjectile)


#define FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAProjectile(); \
	friend struct Z_Construct_UClass_AProjectile_Statics; \
public: \
	DECLARE_CLASS(AProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MusicalAI"), NO_API) \
	DECLARE_SERIALIZER(AProjectile)


#define FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjectile(AProjectile&&); \
	NO_API AProjectile(const AProjectile&); \
public: \
	NO_API virtual ~AProjectile();


#define FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProjectile(AProjectile&&); \
	NO_API AProjectile(const AProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProjectile) \
	NO_API virtual ~AProjectile();


#define FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_12_PROLOG
#define FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_SPARSE_DATA \
	FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_RPC_WRAPPERS \
	FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_ACCESSORS \
	FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_INCLASS \
	FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_SPARSE_DATA \
	FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_ACCESSORS \
	FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_INCLASS_NO_PURE_DECLS \
	FID_MusicalAI_Source_MusicalAI_Public_Projectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MUSICALAI_API UClass* StaticClass<class AProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_MusicalAI_Source_MusicalAI_Public_Projectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
