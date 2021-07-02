// Fill out your copyright notice in the Description page of Project Settings.


#include "UE_MultiplayerTemp/MenuSystem/InGameEscMenu.h"

#include "Components/WidgetSwitcher.h"
#include "Components/Button.h"

bool UInGameEscMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	// Bindings
	// Resume Button
	if (!ensure(EscMenuResumeButton != nullptr)) return false;
	EscMenuResumeButton->OnClicked.AddDynamic(this, &UInGameEscMenu::ResumePressed);

	// Keybinds Button
	if (!ensure(EscMenuKeybindsButton != nullptr)) return false;
	EscMenuKeybindsButton->OnClicked.AddDynamic(this, &UInGameEscMenu::OpenKeybindsMenu);

	// Settings Button
	if (!ensure(EscMenuSettingsButton != nullptr)) return false;
	EscMenuSettingsButton->OnClicked.AddDynamic(this, &UInGameEscMenu::SettingsPressed);


	// Exit Button
	if (!ensure(EscMenuExitButton != nullptr)) return false;
	EscMenuExitButton->OnClicked.AddDynamic(this, &UInGameEscMenu::ExitPressed);


	return true;
}

void UInGameEscMenu::ResumePressed()
{
	MenuTeardown();
}

void UInGameEscMenu::KeybindsPressed()
{

}

void UInGameEscMenu::SettingsPressed()
{
	
}

void UInGameEscMenu::ExitPressed()
{
	if (P_MenuInterface != nullptr)
	{
		MenuTeardown();
		P_MenuInterface->LoadMainMenu();
	}
}

void UInGameEscMenu::OpenKeybindsMenu()
{
	if (!ensure(EscMenuSwitcher != nullptr)) return;
	if (!ensure(KeybindsMenu != nullptr)) return;
	EscMenuSwitcher->SetActiveWidget(KeybindsMenu);
}

void UInGameEscMenu::OpenInGameEscMenu()
{
}
