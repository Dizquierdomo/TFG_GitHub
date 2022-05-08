// Copyright Epic Games, Inc. All Rights Reserved.


#include "UE_TFGGameModeBase.h"

void AUE_TFGGameModeBase::StartPlay()
{
    Super::StartPlay();

    check(GEngine != nullptr);

    // Display a debug message for five seconds. 
    // The -1 "Key" value argument prevents the message from being updated or refreshed.
    GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, TEXT("Using: UE_TFGGameModeBase"));

}