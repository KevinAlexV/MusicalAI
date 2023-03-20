// All rights reserved KevinAlexV. Music used belongs to respective author, and is not in any way claimed to be owned by the developers of this application.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Projectile.generated.h"

class UBoxComponent;

UCLASS()
class MUSICALAI_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool isReleased = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditInstanceOnly, Category = "Projectile")
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY()
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(EditInstanceOnly)
	UProjectileMovementComponent* ProjectileMovement;

	/*UPROPERTY(EditInstanceOnly)
	UBoxComponent* Collider;*/

	void StartMoving(FVector projectileVelo);

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	float lifespan = 0.0f, maxLifespan = 10.0f;
};
