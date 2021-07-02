// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "Blueprint/UserWidget.h"
#include "MenuWidget.h"

#include "InGameEscMenu.generated.h"

/**
 * 
 */
UCLASS()
class UE_MULTIPLAYERTEMP_API UInGameEscMenu : public UMenuWidget
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize();

private:
	UPROPERTY(meta = (BindWidget))
		class UButton* EscMenuResumeButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* EscMenuKeybindsButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* EscMenuSettingsButton;
	
	UPROPERTY(meta = (BindWidget))
		class UButton* EscMenuExitButton;

	// Manage Switcing Menus
	UPROPERTY(meta = (BindWidget))
		class UWidgetSwitcher* EscMenuSwitcher;

	UPROPERTY(meta = (BindWidget))
		class UWidget* KeybindsMenu;

	UFUNCTION()
		void ResumePressed();

	UFUNCTION()
		void KeybindsPressed();

	UFUNCTION()
		void SettingsPressed();

	UFUNCTION()
		void ExitPressed();

	// Opening / closing windows
	UFUNCTION()
		void OpenKeybindsMenu();

	UFUNCTION()
		void OpenInGameEscMenu();

};
