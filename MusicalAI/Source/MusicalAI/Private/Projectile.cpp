// All rights reserved KevinAlexV. Music used belongs to respective author, and is not in any way claimed to be owned by the developers of this application.


#include "Projectile.h"
#include "Components/BoxComponent.h"
#include "NPC.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(FName("Projectile"));
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	SetRootComponent(StaticMesh);

	//StaticMesh->SetupAttachment(DefaultSceneRoot);

	//Collider = CreateDefaultSubobject<UBoxComponent>(FName("Collider"));
	//Collider->SetBoxExtent(FVector(35.0f, 40.0f, 35.0f));
	//Collider->SetupAttachment(StaticMesh);
	//Collider->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("/Game/SetPieces/Objects/Props/MaterialSphere.MaterialSphere"));
	UStaticMesh* Asset = MeshAsset.Object;

	if (Asset)
	{
		UE_LOG(LogTemp, Warning, TEXT("[Projectile] Static Mesh being assigned from MaterialSphere"));
		StaticMesh->SetStaticMesh(Asset);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[Projectile] StaticMesh not found"));
		UKismetSystemLibrary::QuitGame(GetWorld(), 0, EQuitPreference::Quit, true);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("/Game/Characters/CharacterProps/EnergyBallMat.EnergyBallMat"));
	UMaterial* Material = MaterialAsset.Object;

	if (Material)
	{
		UE_LOG(LogTemp, Warning, TEXT("[Projectile] Material being assigned from EnergyBallMat"));
		StaticMesh->SetMaterial(0, Material);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[Projectile] Material not found"));
		UKismetSystemLibrary::QuitGame(GetWorld(), 0, EQuitPreference::Quit, true);
	}

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

	//StaticMesh->SetCollisionObjectType("");
	StaticMesh->SetCollisionProfileName("PlayerProjectile");
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

		float scale = 1.0f - (lifespan / maxLifespan);

		FVector currentScale = StaticMesh->GetRelativeScale3D();

		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, currentScale.ToString());

		StaticMesh->SetRelativeScale3D(FVector(currentScale * scale));

		if (lifespan >= maxLifespan)
		{
			Destroy();
		}
	}
}

void AProjectile::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	
	if (ANPC* TargetActor = Cast<ANPC>(OtherActor))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Overlapped NPC"));
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Overlapped NPC");
		//Destroy();
		//TargetActor->OnAttack_Implementation(damage, NULL);
	}
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Overlapped");
}

void AProjectile::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Destroy();
}

void AProjectile::StartMoving(FVector projectileVelo) 
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, projectileVelo.ToString());
	ProjectileMovement->SetVelocityInLocalSpace(FVector(projectileVelo));
}