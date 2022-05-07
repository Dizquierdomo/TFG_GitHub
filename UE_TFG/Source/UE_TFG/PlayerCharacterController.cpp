// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterController.h"
#include "EngineUtils.h"
#include "UObject/NameTypes.h"
#include "Gladiator.h"

// Sets default values
APlayerCharacterController::APlayerCharacterController() {
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    isGamePaused = false;
}

// Called when the game starts or when spawned
void APlayerCharacterController::BeginPlay() {
    Super::BeginPlay();

    
    // Search for player character.
    for (TActorIterator<AGladiator> It(GetWorld()); It; ++It) {
        AGladiator* aux = *It; 
        // If found player character save his reference in playerCaracter.
        if (aux->GetActorLabel() == TEXT("Player")) {
            playerCharacter = aux;
        }
    }      
    
    // Set up camera component in player character as active camera.
    if (playerCharacter != nullptr) {
        SetViewTarget(playerCharacter);
    }
    
}

// Called every frame
void APlayerCharacterController::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacterController::SetupInputComponent() {
    Super::SetupInputComponent();
    /*
    // Set up "movement" bindings.
    InputComponent->BindAxis("MoveForward", this, &APlayerCharacterController::MoveForward);
    InputComponent->BindAxis("MoveBackward", this, &APlayerCharacterController::MoveBackward);
    InputComponent->BindAxis("MoveRight", this, &APlayerCharacterController::MoveRight);
    InputComponent->BindAxis("MoveLeft", this, &APlayerCharacterController::MoveLeft);

    InputComponent->BindAxis("RotateCameraX", this, &APlayerCharacterController::RotateCameraX);
    InputComponent->BindAxis("RotateCameraY", this, &APlayerCharacterController::RotateCameraY);    
    */

    // Set up "pause game action" bindings.
    InputComponent->BindAction("PauseGame", IE_Pressed, this, &APlayerCharacterController::PauseGame);
}

/*
// Transfer input Axis "MoveForward" values to player character.
void APlayerCharacterController::MoveForward(float inputAxisValue) {
    if (inputAxisValue > 0.0f && playerCharacter != nullptr) {
GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, TEXT("Forward"));
        playerCharacter->MoveForward(inputAxisValue);        
    }    
}

// Transfer input Axis "MoveBackward" values to player character.
void APlayerCharacterController::MoveBackward(float inputAxisValue) {
    if (inputAxisValue < 0.0f && playerCharacter != nullptr) {
GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, TEXT("Backward"));
        playerCharacter->MoveBackward(inputAxisValue);
    }
}

// Transfer input Axis "MoveRight" values to player character.
void APlayerCharacterController::MoveRight(float inputAxisValue) {
    if (inputAxisValue > 0.0f && playerCharacter != nullptr) {
GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, TEXT("Right"));
        playerCharacter->MoveRight(inputAxisValue);
    }
}

// Transfer input Axis "MoveLeft" values to player character.
void APlayerCharacterController::MoveLeft(float inputAxisValue) {
    if (inputAxisValue < 0.0f && playerCharacter != nullptr) {
GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, TEXT("Left"));
        playerCharacter->MoveLeft(inputAxisValue);
    }
}
*/

// Transfer input Key "PauseGame" values to player character.
void APlayerCharacterController::PauseGame() {
    if (!isGamePaused) {
GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Blue, TEXT("Game paused"));
        isGamePaused = true;
    } else {
GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Blue, TEXT("Game released"));
        isGamePaused = false;
    }
}

/*
void APlayerCharacterController::RotateCameraX(float inputAxisValue) {
    if (inputAxisValue != 0.0f && playerCharacter != nullptr) {
        playerCharacter->AddControllerYawInput(inputAxisValue);
        UE_LOG(LogTemp, Warning, TEXT("X value: %f"), inputAxisValue);        
    }
}

void APlayerCharacterController::RotateCameraY(float inputAxisValue) {
    if (inputAxisValue != 0.0f && playerCharacter != nullptr) {
        playerCharacter->AddControllerPitchInput(inputAxisValue);
        UE_LOG(LogTemp, Warning, TEXT("Y value: %f"), inputAxisValue);
    }
}
*/