// Fill out your copyright notice in the Description page of Project Settings.


#include "UE_MultiplayerTemp/MenuSystem/InGameEscMenu.h"
#include "Components/Button.h"

bool UInGameEscMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	// Bindings
	// Resume Button
	if (!ensure(EscMenuResumeButton != nullptr)) return false;
	EscMenuResumeButton->OnClicked.AddDynamic(this, &UInGameEscMenu::ResumePressed);

	// Exit Button
	if (!ensure(EscMenuExitButton != nullptr)) return false;
	EscMenuExitButton->OnClicked.AddDynamic(this, &UInGameEscMenu::ExitPressed);


	return true;
}

void UInGameEscMenu::ResumePressed()
{
	MenuTeardown();
}

void UInGameEscMenu::ExitPressed()
{
	if (P_MenuInterface != nullptr)
	{
		MenuTeardown();
		P_MenuInterface->LoadMainMenu();
	}
}
