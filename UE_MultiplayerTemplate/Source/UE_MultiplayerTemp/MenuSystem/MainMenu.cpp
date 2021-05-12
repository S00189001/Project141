// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"

#include "Uobject/ConstructorHelpers.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"

#include "ServerRow.h"

UMainMenu::UMainMenu(const FObjectInitializer& ObjectInitializer)
{
	// To link BP classes - Server Row BP
	ConstructorHelpers::FClassFinder<UUserWidget> ServerRowBPClass(TEXT("/Game/MenuSystem/WBP_ServerRow"));
	if (!ensure(ServerRowBPClass.Class != nullptr)) return;
	ServerRowClass = ServerRowBPClass.Class;
}

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	// Binding to a button in Main Menu (Host)
	if (!ensure(HostButton != nullptr)) return false;
	// Call for binding
	HostButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	// Binding to a button in Main Menu (Join)
	if (!ensure(JoinButton != nullptr)) return false;
	// Call for binding
	JoinButton->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);

	// Binding to a button in Main Menu (Exit)
	if (!ensure(ExitButton != nullptr)) return false;
	// Call for binding
	ExitButton->OnClicked.AddDynamic(this, &UMainMenu::ExitGame);

	// Binding to a button in Main Menu (Back)
	if (!ensure(CancelJoinMenuButton != nullptr)) return false;
	// Call for binding
	CancelJoinMenuButton->OnClicked.AddDynamic(this, &UMainMenu::OpenMainMenu);

	// Binding to a button in Main Menu (JoinServer)
	if (!ensure(ConfirmJoinMenuButton != nullptr)) return false;
	// Call for binding
	ConfirmJoinMenuButton->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);

	return true;
}

void UMainMenu::HostServer()
{
	//UE_LOG(LogTemp, Warning, TEXT("I'm Going to host a Server!"));

	if (P_MenuInterface != nullptr)
	{
		P_MenuInterface->Host();
	}

}

void UMainMenu::SetServerList(TArray<FString> ServerNames)
{
	UWorld* World = this->GetWorld();
	if (!ensure(World != nullptr)) return;

	ServerList->ClearChildren();

	for (const FString& ServerName : ServerNames)
	{
		UServerRow* Row = CreateWidget<UServerRow>(World, ServerRowClass);
		if (!ensure(Row != nullptr)) return;

		// Text To Display on Server List
		Row->ServerName->SetText(FText::FromString(ServerName));

		ServerList->AddChild(Row);
	}


}

void UMainMenu::JoinServer()
{
	if (P_MenuInterface != nullptr)
	{
		/* Get the entered IP Address String*/
		/*if (!ensure(IPAddressField != nullptr)) return;
		const FString& Address = IPAddressField->GetText().ToString();*/
		//P_MenuInterface->Join(Address);

		P_MenuInterface->Join("");


	}
}

void UMainMenu::OpenJoinMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(JoinMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(JoinMenu);

	if (P_MenuInterface != nullptr)
	{
		P_MenuInterface->RefreshingServerList();
	}


}

void UMainMenu::OpenMainMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(JoinMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(MainMenu);
}

void UMainMenu::ExitGame()
{
	CloseApplication();
}