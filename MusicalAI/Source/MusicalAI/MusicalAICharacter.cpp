// Copyright Epic Games, Inc. All Rights Reserved.

#include "MusicalAICharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/PlayerCameraManager.h"
#include "MusicalAIGameMode.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

//////////////////////////////////////////////////////////////////////////
// Misc Functions

void AMusicalAICharacter::rotateToCamera(UPaperFlipbookComponent* PaperFlipbook) 
{

	// Get the camera location
	FVector cameraLocation = GetWorld()->GetFirstPlayerController()->PlayerCameraManager->GetCameraLocation();//FollowCamera->GetComponentTransform().GetLocation();//
	
	// Get the character location
	FVector characterLocation = PaperFlipbook->GetComponentLocation();

	// Get the direction from the character to the camera
	//FVector direction = cameraLocation - characterLocation;

	FRotator PlayerRot = UKismetMathLibrary::FindLookAtRotation(cameraLocation, characterLocation);

	PlayerRot = FRotator(0.0, PlayerRot.Yaw + 90.0, PlayerRot.Roll);

	// Rotate the character to face the camera
	PaperFlipbook->SetWorldRotation(PlayerRot);
}

FVector AMusicalAICharacter::GetProjectileDirection()
{

	// Get the camera location
	FVector cameraLocation = FollowCamera->GetComponentTransform().GetLocation();
	
	// Get the character location
	FVector capsuleLocation = this->GetCapsuleComponent()->GetComponentLocation();
	
	// Get the direction from the character to the camera
	FVector direction = capsuleLocation - cameraLocation;
	direction.Normalize(0.1f);
	direction = FVector(direction.X, direction.Y, 0.0);

	return direction;
}

//////////////////////////////////////////////////////////////////////////
// AMusicalAICharacter

AMusicalAICharacter::AMusicalAICharacter()
{
	
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Create a paper flipbook component
	PlayerCharacter = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("PaperFlipbook"));
	PlayerCharacter->SetupAttachment(RootComponent);


	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

void AMusicalAICharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AMusicalAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(PlayerCharacter)
		rotateToCamera(PlayerCharacter);
}

//////////////////////////////////////////////////////////////////////////
// Input

void AMusicalAICharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMusicalAICharacter::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMusicalAICharacter::Look);

		//Attack B
		EnhancedInputComponent->BindAction(AttackBAction, ETriggerEvent::Triggered, this, &AMusicalAICharacter::TriggerAttackB);
		EnhancedInputComponent->BindAction(AttackBAction, ETriggerEvent::Started, this, &AMusicalAICharacter::StartAttackB);
		EnhancedInputComponent->BindAction(AttackBAction, ETriggerEvent::Canceled, this, &AMusicalAICharacter::FinishAttackB);
		EnhancedInputComponent->BindAction(AttackBAction, ETriggerEvent::Completed, this, &AMusicalAICharacter::FinishAttackB);
	}

}

void AMusicalAICharacter::TriggerAttackB(const FInputActionValue& Value)
{
	FTransform ProjectileTransform = FTransform(FRotator(0.0, 0.0, 0.0), PlayerCharacter->GetComponentTransform().GetLocation(), FVector(0.25, 0.25, 0.25));

	canMove = false;

	if (Projectile == nullptr || Projectile->isReleased)
	{
		Projectile = GetWorld()->SpawnActorDeferred<AProjectile>(AProjectile::StaticClass(), ProjectileTransform, this, this, ESpawnActorCollisionHandlingMethod::DontSpawnIfColliding);

		ProjectileDirection = GetProjectileDirection();
		Projectile->StartMoving(FVector(ProjectileDirection.X * 500.0, ProjectileDirection.Y * 500.0, ProjectileDirection.Z * 500.0));

		Projectile->FinishSpawning(ProjectileTransform);
	}

	//UE_LOG(LogTemp, Warning, TEXT("AttackB"));
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "AttackB");
}

void AMusicalAICharacter::StartAttackB(const FInputActionValue& Value)
{

	//UE_LOG(LogTemp, Warning, TEXT("AttackB"));
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "AttackB");
}

void AMusicalAICharacter::FinishAttackB(const FInputActionValue& Value)
{
	if (Projectile != nullptr)
	{

		Projectile->isReleased = true;
	}
	//UE_LOG(LogTemp, Warning, TEXT("AttackB"));
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "AttackB");


	canMove = true;
}

void AMusicalAICharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr && canMove)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AMusicalAICharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}