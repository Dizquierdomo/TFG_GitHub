// Fill out your copyright notice in the Description page of Project Settings.


#include "Gladiator.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AGladiator::AGladiator()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// set our turn rates for input
	BaseCameraXRate = 45.0f;
	BaseCameraYRate = 45.0f;
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate

	// Create a camera arm (pulls in towards the player if there is a collision)
	cameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));
	cameraArm->SetupAttachment(RootComponent);
	cameraArm->TargetArmLength = 260.0f; // The camera follows at this distance behind the character	
	cameraArm->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	//cameraComponent->SetupAttachment(RootComponent);
	cameraComponent->SetupAttachment(cameraArm, USpringArmComponent::SocketName); // Attach the camera to the end of the spring arm and let the spring arm adjust to match the controller orientation
	cameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	//cameraComponent->SetRelativeLocation(FVector(-260.0f, 0.0f, 140.0f));
	//cameraComponent->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));
}

// Called when the game starts or when spawned
void AGladiator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGladiator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGladiator::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGladiator::MoveForward(float inputAxisValue) {
	check(GEngine != nullptr);

	// Display a debug message for five seconds. 
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, TEXT("Forward"));
	// Find out which way is "forward" and record that the player wants to move that way.
	// find out which way is forward
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get forward vector
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, inputAxisValue);
}

void AGladiator::MoveBackward(float inputAxisValue) {
	check(GEngine != nullptr);

	// Display a debug message for five seconds. 
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, TEXT("Backward"));
	
	// Find out which way is "forward" and record that the player wants to move that way.
	// find out which way is forward
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get forward vector
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, inputAxisValue);
}

void AGladiator::MoveRight(float inputAxisValue) {
	check(GEngine != nullptr);

	// Display a debug message for five seconds. 
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, TEXT("Right"));
	// find out which way is right
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get right vector 
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	// add movement in that direction
	AddMovementInput(Direction, inputAxisValue);
} 

void AGladiator::MoveLeft(float inputAxisValue) {
	check(GEngine != nullptr);

	// Display a debug message for five seconds. 
	// The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Red, TEXT("Left"));
	// find out which way is right
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get right vector 
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	// add movement in that direction
	AddMovementInput(Direction, inputAxisValue);
}