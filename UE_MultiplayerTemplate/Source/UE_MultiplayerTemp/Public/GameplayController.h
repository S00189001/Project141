// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <UE_MultiplayerTemp/UE_MultiplayerTempCharacter.h>
#include "GameplayController.generated.h"



/**
 * 
 */
UCLASS()
class UE_MULTIPLAYERTEMP_API AGameplayController : public APlayerController
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, Category = "Utilities")
	void AddItemToInvetoryByID(FName ID);

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	class AInteractable* CurrentInteractable;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TArray<FInvetoryItem> Invetory;

	

protected:

	void Interact();

	virtual void SetupInputComponent() override;
	
};
