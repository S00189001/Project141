// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"
#include <UE_MultiplayerTemp/UE_MultiplayerTempCharacter.h>

APickup::APickup()
{
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");

	ItemID = FName("Please enter an ID");
}