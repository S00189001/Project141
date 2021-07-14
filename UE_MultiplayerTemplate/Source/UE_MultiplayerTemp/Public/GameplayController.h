// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameplayController.generated.h"

/**
 * 
 */
UCLASS()
class UE_MULTIPLAYERTEMP_API AGameplayController : public APlayerController
{
	GENERATED_BODY()

public:
	
	class AInteractable* CurrentInteractable;
	
};
