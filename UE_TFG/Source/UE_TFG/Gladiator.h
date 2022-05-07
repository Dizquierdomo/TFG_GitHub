// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Gladiator.generated.h"

UCLASS()
class UE_TFG_API AGladiator : public ACharacter
{
	GENERATED_BODY()

//public:
	UPROPERTY(EditAnywhere)
	class UCameraComponent* cameraComponent;
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* cameraArm;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(EditAnywhere, Category = Camera)
	float BaseCameraXRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(EditAnywhere, Category = Camera)
	float BaseCameraYRate;

public:
	// Sets default values for this character's properties
	AGladiator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float inputAxisValue);
	void MoveBackward(float inputAxisValue);
	void MoveRight(float inputAxisValue);
	void MoveLeft(float inputAxisValue);
};

