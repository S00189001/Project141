// Fill out your copyright notice in the Description page of Project Settings.

#include "UE_MultiplayerTemp/MenuSystem/LobbyMenu.h"

#include "Components/WidgetSwitcher.h"
#include "Components/Button.h"

bool ULobbyMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	// Bindings
	// Start Game Button
	if (!ensure(LobbyMenuStartButton != nullptr)) return false;
	LobbyMenuStartButton->OnClicked.AddDynamic(this, &ULobbyMenu::StartPressed);

	// Leave Game Button
	if (!ensure(LobbyMenuLeaveButton != nullptr)) return false;
	LobbyMenuLeaveButton->OnClicked.AddDynamic(this, &ULobbyMenu::LeavePressed);


	return true;
}

void ULobbyMenu::StartPressed()
{
	if (P_MenuInterface != nullptr)
	{
		//FString ServerName = ServerHostName->Text.ToString();
		P_MenuInterface->Host("LobbySession");
	}
}

void ULobbyMenu::LeavePressed()
{
}
