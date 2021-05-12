// Fill out your copyright notice in the Description page of Project Settings. cpp


#include "MasterGameInstance.h"

#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "OnlineSessionSettings.h"

#include "PlatformTrigger.h"
// Not Moduler <Here>
#include "UE_MultiplayerTemp/MenuSystem/MainMenu.h"
#include "UE_MultiplayerTemp/MenuSystem/MenuWidget.h"

const static FName SESSION_NAME = TEXT("My Session Game");

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
	// Get Interface
	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	if (Subsystem != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found Subsystem %s"), *Subsystem->GetSubsystemName().ToString());
		SessionInterface = Subsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			//UE_LOG(LogTemp, Warning, TEXT("Found Session Interface"));
			// Delegate
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UMasterGameInstance::OnCreateSessionComplete);
			SessionInterface->OnDestroySessionCompleteDelegates.AddUObject(this, &UMasterGameInstance::OnDestroySessionComplete);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &UMasterGameInstance::OnFindSessionsComplete);
			SessionInterface->OnJoinSessionCompleteDelegates.AddUObject(this, &UMasterGameInstance::OnJoinSessionComplete);

		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found No Subsystem"));
	}

	//UE_LOG(LogTemp, Warning, TEXT("Found Class %s"), *MenuClass->GetName());


}

void UMasterGameInstance::LoadMenuWidget()
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
	if (SessionInterface.IsValid())
	{
		// Check if Session Exists
		auto ExitingSession = SessionInterface->GetNamedSession(SESSION_NAME);
		if (ExitingSession != nullptr)
		{
			SessionInterface->DestroySession(SESSION_NAME);
		}
		else
		{
			CreateSession();
		}

	}
}

void UMasterGameInstance::OnDestroySessionComplete(FName SessionName, bool Success)
{
	if (Success)
	{
		CreateSession();
	}
}

void UMasterGameInstance::CreateSession()
{
	if (SessionInterface.IsValid())
	{
		// Create Session + Setting Settings
		FOnlineSessionSettings SessionSettings;
		SessionSettings.bIsLANMatch = false;
		SessionSettings.NumPublicConnections = 2;
		SessionSettings.bShouldAdvertise = true;
		// For Steam
		SessionSettings.bUsesPresence = true;

		SessionInterface->CreateSession(0, SESSION_NAME, SessionSettings);
	}

}

void UMasterGameInstance::OnCreateSessionComplete(FName SessionName, bool Success)
{
	if (!Success)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could Not Create Session"));
		return;
	}
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

void UMasterGameInstance::RefreshingServerList()
{
	SessionSearch = MakeShareable(new FOnlineSessionSearch());
	if (SessionSearch.IsValid())
	{
		// because of sharing an app id
		SessionSearch->MaxSearchResults = 100;
		// Steam - Allows for search presence
		SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);

		SessionSearch->bIsLanQuery = true;
		//SessionSearch->QuerySettings.
		UE_LOG(LogTemp, Warning, TEXT("Starting Find Session"));
		SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
	}
}

void UMasterGameInstance::OnFindSessionsComplete(bool Success)
{

	if (Success && SessionSearch.IsValid() && Menu != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Finished Find Session"));

		TArray<FString> ServerNames;
		// Test Data
		ServerNames.Add("Test Server 1");
		ServerNames.Add("Test Server 2");
		ServerNames.Add("Test Server 3");
		ServerNames.Add("Test Server 4");

		for (const FOnlineSessionSearchResult& SearchResult : SessionSearch->SearchResults)
		{
			UE_LOG(LogTemp, Warning, TEXT("Found Session Name: %s"), *SearchResult.GetSessionIdStr());
			ServerNames.Add(SearchResult.GetSessionIdStr());
		}

		Menu->SetServerList(ServerNames);
	}
}

void UMasterGameInstance::Join(uint32 Index)
{
	if (!SessionInterface.IsValid()) return;
	if (!SessionSearch.IsValid()) return;

	SessionInterface->JoinSession(0, SESSION_NAME, SessionSearch->SearchResults[Index]);


	if (Menu != nullptr)
	{
		Menu->MenuTeardown();
	}




}

void UMasterGameInstance::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	if (!SessionInterface.IsValid()) return;

	FString Address;
	if (!SessionInterface->GetResolvedConnectString(SessionName, Address))
	{
		UE_LOG(LogTemp, Warning, TEXT("Could NOT get connect String"));
		return;
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