// Fill out your copyright notice in the Description page of Project Settings. cpp


#include "MasterGameInstance.h"

#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

#include "PlatformTrigger.h"
// Not Moduler <Here>
#include "UE_MultiplayerTemp/MenuSystem/MainMenu.h"
#include "UE_MultiplayerTemp/MenuSystem/MenuWidget.h"

UMasterGameInstance::UMasterGameInstance(const FObjectInitializer& ObjectInitializer)
{
	// To link BP classes - Main Menu BP
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	if (!ensure(MenuBPClass.Class != nullptr)) return;
	MenuClass = MenuBPClass.Class;

	// Esc Menu BP
	ConstructorHelpers::FClassFinder<UUserWidget> InGameEscMenuBPClass(TEXT("/Game/MenuSystem/WBP_InGameEscMenu"));
	if (!ensure(InGameEscMenuBPClass.Class != nullptr)) return;
	InGameEscMenuClass = InGameEscMenuBPClass.Class;

	// Print name of found class
	//UE_LOG(LogTemp, Warning, TEXT("Found Class %s"), *MenuBPClass.Class->GetName());
}

void UMasterGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Found Class %s"), *MenuClass->GetName());

	// Logs to the Console
	//UE_LOG(LogTemp, Warning, TEXT("Game Instance Init"));
}

void UMasterGameInstance::LoadMenu()
{
	if (!ensure(MenuClass != nullptr)) return;
	Menu = CreateWidget<UMainMenu>(this, MenuClass);
	if (!ensure(Menu != nullptr)) return;

	// Call Menu Setup
	Menu->Setup();

	Menu->SetMenuInterface(this);

}

void UMasterGameInstance::InGameLoadMenu()
{
	if (!ensure(InGameEscMenuClass != nullptr)) return;
	UMenuWidget* L_Menu = CreateWidget<UMenuWidget>(this, InGameEscMenuClass);
	if (!ensure(L_Menu != nullptr)) return;

	// Call Menu Setup
	L_Menu->Setup();

	L_Menu->SetMenuInterface(this);
}

void UMasterGameInstance::Host()
{
	if (Menu != nullptr)
	{
		Menu->MenuTeardown();
	}

	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UMasterGameInstance::Join(const FString& Address)
{
	if (Menu != nullptr)
	{
		Menu->MenuTeardown();
	}

	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	// Get Player Controller
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);

}

void UMasterGameInstance::LoadMainMenu()
{
	// Get Player Controller
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel("/Game/MenuSystem/MainMenu", ETravelType::TRAVEL_Absolute);
}