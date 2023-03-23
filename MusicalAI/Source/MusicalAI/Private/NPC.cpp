// All rights reserved KevinAlexV. Music used belongs to respective author, and is not in any way claimed to be owned by the developers of this application.


#include "NPC.h"

// Sets default values
ANPC::ANPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANPC::OnAttack_Implementation(float damage, AActor* Attacker)
{
	UE_LOG(LogTemp, Warning, TEXT("NPC was attacked!"));
	/*if (object != nullptr && IMyInterface::ImplementsInterface(object))
	{
		UActorComponent* myComp = IMyInterface::Execute_GetSomeComponent(object)
	}*/
}