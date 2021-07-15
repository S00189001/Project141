// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"

#define COLLISION_INTERACTABLE ECC_GameTraceChannel1;

//UENUM(BlueprintType)
//enum class EGASAbilityInputID : unit32
//{
//	None,
//	Confirm,
//	Cancel,
//	Punch
//};

UENUM(BlueprintType)
enum class EGASAbilityInputID : uint8
{
	None,
	Confirm,
	Cancel,
	Punch,
	BuffAttackPower
};