// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"
#include <UE_MultiplayerTemp/UE_MultiplayerTempCharacter.h>


// Sets default values
AInteractable::AInteractable()
{
 
	Name = "Name not set";
	Action = "Interact";
}

// Called when the game starts or when spawned
void AInteractable::BeginPlay()
{
	Super::BeginPlay();
	
}



