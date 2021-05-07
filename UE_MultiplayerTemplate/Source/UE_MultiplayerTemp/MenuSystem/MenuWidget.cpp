// Fill out your copyright notice in the Description page of Project Settings.


#include "UE_MultiplayerTemp/MenuSystem/MenuWidget.h"

void UMenuWidget::Setup()
{
	// Display Menu
	this->AddToViewport();

	// Get World
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	// Get first Player Controller
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	// *** 
	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(this->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

	// Set Input mode for Player Controller
	PlayerController->SetInputMode(InputModeData);

	// Set Mouse visibility = true for Player Controller
	PlayerController->SetShowMouseCursor(true);
	//***1
}

void UMenuWidget::MenuTeardown()
{
	// Remove Menu From Veiwport
	this->RemoveFromViewport();

	// Get World
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	// Get first Player Controller
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	// Set Input mode for Player Controller
	FInputModeGameOnly InputModeData;
	PlayerController->SetInputMode(InputModeData);

	// Set Mouse visibility = true for Player Controller
	PlayerController->SetShowMouseCursor(false);

}

void UMenuWidget::SetMenuInterface(IMenuInterface* MenuInterface)
{
	P_MenuInterface = MenuInterface;
}

void UMenuWidget::CloseApplication()
{
	// Get World
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	// Get first Player Controller
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	// Exit Game
	PlayerController->ConsoleCommand("quit");
}