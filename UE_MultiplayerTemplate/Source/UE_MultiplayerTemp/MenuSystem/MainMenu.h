// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "Blueprint/UserWidget.h"
#include "MenuWidget.h"
//#include "Components/EditableTextBox.h"

#include "MainMenu.generated.h"

USTRUCT()
struct FServerData
{
	GENERATED_BODY();

	// Server Name
	FString Name;
	//  Current Players
	uint16 CurrentPlayers;
	// Max Players
	uint16 MaxPlayers;
	// Server / Host Username
	FString HostUsername;
};

/**
 * 
 */
UCLASS()
class UE_MULTIPLAYERTEMP_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()
public:
	// Constructor
	UMainMenu(const FObjectInitializer& ObjectInitializer);

	void SetServerList(TArray<FServerData> ServerNames);

	void SelectIndex(uint32 Index);

protected:
	virtual bool Initialize();

private:

	TSubclassOf<class UUserWidget> ServerRowClass;

	UPROPERTY(meta = (BindWidget))
		class UButton* HostButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* OptionsButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* ExitButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* CancelJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* ConfirmJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* CancelHostMenuButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* ConfirmHostMenuButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* StartLobbyMenuButton;

	UPROPERTY(meta = (BindWidget))
		class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
		class UWidget* JoinMenu;
	
	UPROPERTY(meta = (BindWidget))
		class UWidget* HostMenu;

	UPROPERTY(meta = (BindWidget))
		class UWidget* LobbyMenu;

	UPROPERTY(meta = (BindWidget))
		class UEditableTextBox* ServerHostName;

	UPROPERTY(meta = (BindWidget))
		class UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
		class UPanelWidget* ServerList;

	/*UPROPERTY(meta = (BindWidget))
		class UEditableTextBox* IPAddressField;*/


	UFUNCTION()
		void HostServer();

	UFUNCTION()
		void JoinServer();

	UFUNCTION()
		void ExitGame();
	
	UFUNCTION()
		void OpenJoinMenu();

	UFUNCTION()
		void OpenHostMenu();

	UFUNCTION()
		void OpenOptionsMenu();

	UFUNCTION()
		void OpenMainMenu();

	/*UFUNCTION()
		void StartGame();*/

	void UpdateChildren();

	TOptional<uint32> SelectedIndex;
};
