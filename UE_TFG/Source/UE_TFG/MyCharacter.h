// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS(config = Game)
class AMyCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsWalkingForward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsWalkingBackward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsWalkingRight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool IsWalkingLeft;


	AMyCharacter();
	
protected:
	/** Called for forwards/backward input */
	void ForwardMove(float Value);

	void BackwardMove(float Value);

	/** Called for right/left input */
	void RightMove(float Value);
	void LeftMove(float Value);

protected:
	/** Allows the character to receive inputs  **/
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

