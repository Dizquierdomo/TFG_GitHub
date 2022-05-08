// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class UE_TFG_API APlayerCharacterController : public APlayerController
{
	GENERATED_BODY()

private:
	bool isGamePaused;
	class AGladiator* playerCharacter;
	
public:
	// Sets default values for this character's properties
	APlayerCharacterController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupInputComponent() override;

	/*
	void MoveForward(float inputAxisValue);
	void MoveBackward(float inputAxisValue);
	void MoveRight(float inputAxisValue);
	void MoveLeft(float inputAxisValue);

	void RotateCameraX(float inputAxisValue);	
	void RotateCameraY(float inputAxisValue);	
	*/

	void PauseGame();

};
