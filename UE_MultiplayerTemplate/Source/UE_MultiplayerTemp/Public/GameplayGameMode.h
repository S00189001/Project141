// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include <UE_MultiplayerTemp/UE_MultiplayerTempCharacter.h>
#include "GameplayGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UE_MULTIPLAYERTEMP_API AGameplayGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:

	class UDataTable* GetItemDB() const { return ItemDB; }

protected:

	UPROPERTY(EditDefaultsOnly)
	class UDataTable* ItemDB;
};
