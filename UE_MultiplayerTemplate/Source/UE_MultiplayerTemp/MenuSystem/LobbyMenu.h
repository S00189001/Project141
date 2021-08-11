// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "LobbyMenu.generated.h"

/**
 * 
 */
UCLASS()
class UE_MULTIPLAYERTEMP_API ULobbyMenu : public UMenuWidget
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize();

private:
	// Properties
	UPROPERTY(meta = (BindWidget))
		class UButton* LobbyMenuStartButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* LobbyMenuLeaveButton;

	// Functions
	UFUNCTION()
		void StartPressed();

	UFUNCTION()
		void LeavePressed();
};
