// All rights reserved KevinAlexV. Music used belongs to respective author, and is not in any way claimed to be owned by the developers of this application.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
//#include "I_Attackable.h"
#include "NPC.generated.h"

UCLASS()
class MUSICALAI_API ANPC : public ACharacter//, public II_Attackable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//virtual void OnAttack_Implementation(float damage, AActor* Attacker) override;

};
