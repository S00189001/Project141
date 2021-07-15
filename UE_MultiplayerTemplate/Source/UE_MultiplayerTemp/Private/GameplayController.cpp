// Fill out your copyright notice in the Description page of Project Settings.

#include "UE_MultiplayerTemp.generated.h"
#include "Interactable.h"
#include "GameplayGameMode.h"
#include <UE_MultiplayerTemp/UE_MultiplayerTempCharacter.h>
#include "GameplayController.h"


void AGameplayController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Use", IE_Pressed, this, &AGameplayController::Interact);
}

void AGameplayController::Interact()
{
	if (CurrentInteractable)
	{
		CurrentInteractable->Interact(this);
	}
}

void AGameplayController::AddItemToInvetoryByID(FName ID)
{
	AGameplayGameMode* GameMode = Cast<AGameplayGameMode>(GetWorld()->GetAuthGameMode());
	UDataTable* ItemTable = GameMode->GetItemDB();

	FInvetoryItem* ItemToAdd = ItemTable->FindRow<FInvetoryItem>(ID, "");

	if (ItemToAdd)
	{
		Invetory.Add(*ItemToAdd);
	}
}


