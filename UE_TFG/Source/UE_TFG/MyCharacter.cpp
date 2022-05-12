// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

AMyCharacter::AMyCharacter() {
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(45.f, 95.0f);
	
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Make that this character moves in the direction of input and set the rotation rate
	GetCharacterMovement()->bOrientRotationToMovement = true; 	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); 	

	// Create a camera boom 
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f;			// The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true;		// Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);		// Attach the camera to the end of the arm and let the arm adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false;									// Camera does not rotate relative to arm		
}

void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) {
	// Set up key/axis bindings
	check(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::ForwardMove);
	PlayerInputComponent->BindAxis("MoveBackward", this, &AMyCharacter::BackwardMove);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::RightMove);
	PlayerInputComponent->BindAxis("MoveLeft", this, &AMyCharacter::LeftMove);
		
	PlayerInputComponent->BindAxis("RotateCameraX", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("RotateCameraY", this, &APawn::AddControllerPitchInput);
}

void AMyCharacter::ForwardMove(float Value) {
	
	if ((Controller != nullptr) && (Value != 0.0f))	{
		IsWalkingForward = true;

		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value / 2);

	} else {
		IsWalkingForward = false;
	}
}

void AMyCharacter::BackwardMove(float Value) {		

	if ((Controller != nullptr) && (Value != 0.0f)) {
		IsWalkingBackward = true;

		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value / 2);
	} else {
		IsWalkingBackward = false;
	}
}

void AMyCharacter::RightMove(float Value) {
	
	if ((Controller != nullptr) && (Value != 0.0f))	{
		IsWalkingRight = true;

		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value / 2);
	} else {
		IsWalkingRight = false;		
	}
}

void AMyCharacter::LeftMove(float Value) {

	if ((Controller != nullptr) && (Value != 0.0f)) {
		IsWalkingLeft = true;

		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value / 2);
	}
	else {
		IsWalkingLeft = false;
	}
}