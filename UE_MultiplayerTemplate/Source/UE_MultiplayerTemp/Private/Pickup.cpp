// Fill out your copyright notice in the Description page of Project Settings.

#include "UE_MultiplayerTemp.generated.h"
#include "Pickup.h"

APickup::APickup()
{
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");

	ItemID = FName("Please enter an ID");
}