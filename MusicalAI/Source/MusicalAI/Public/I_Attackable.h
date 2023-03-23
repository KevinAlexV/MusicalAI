// All rights reserved KevinAlexV. Music used belongs to respective artist, and is not in any way claimed to be owned by the developers of this application.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "I_Attackable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UI_Attackable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MUSICALAI_API II_Attackable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable = true, BlueprintNativeEvent, Category = "Attackable")
	void OnAttack(float damage, AActor* Attacker);
};
