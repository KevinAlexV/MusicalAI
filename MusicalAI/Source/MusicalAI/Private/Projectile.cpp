// All rights reserved KevinAlexV. Music used belongs to respective author, and is not in any way claimed to be owned by the developers of this application.


#include "Projectile.h"
#include "Components/BoxComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(FName("Projectile"));
	SetRootComponent(DefaultSceneRoot);
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	StaticMesh->SetupAttachment(DefaultSceneRoot);

	//Collider = CreateDefaultSubobject<UBoxComponent>(FName("Collider"));
	//Collider->SetBoxExtent(FVector(35.0f, 40.0f, 35.0f));
	//Collider->SetupAttachment(StaticMesh);
	//Collider->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));


	//Projectile Movement Component Declaration
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));

	ProjectileMovement->ProjectileGravityScale = 0.0f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->Friction = 0.0f;
	ProjectileMovement->bRotationRemainsVertical = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->bIsHomingProjectile = false;
	ProjectileMovement->bInitialVelocityInLocalSpace = false;
	ProjectileMovement->bRotationFollowsVelocity = true;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	StaticMesh->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::OverlapBegin);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isReleased)
	{
		lifespan += DeltaTime;
		if (lifespan >= maxLifespan)
		{
			Destroy();
		}
	}
}

void AProjectile::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	UE_LOG(LogTemp, Warning, TEXT("Overlapped projectile"));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Overlapped projectile");
	//Destroy();
}

void AProjectile::StartMoving(FVector projectileVelo) 
{
	
	ProjectileMovement->SetVelocityInLocalSpace(FVector(projectileVelo.X * 500.0, projectileVelo.Y * 500.0, projectileVelo.Z * 500.0));

}