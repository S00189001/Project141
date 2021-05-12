// Fill out your copyright notice in the Description page of Project Settings.


#include "UE_MultiplayerTemp/MenuSystem/ServerRow.h"

#include "Components/Button.h"
#include "MainMenu.h"

void UServerRow::Setup(class UMainMenu* InParent, uint32 InIndex)
{
	Parent = InParent;
	Index = InIndex;

	// Binding Server Row Button
	RowButton->OnClicked.AddDynamic(this, &UServerRow::OnClicked);
}

void UServerRow::OnClicked()
{
	Parent->SelectIndex(Index);
}