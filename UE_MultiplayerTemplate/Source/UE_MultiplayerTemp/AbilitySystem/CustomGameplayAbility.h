// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GASGameplayAbility.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayEffect.h"

#include "CustomGameplayAbility.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum ElementType
{
	None,
	Fire,
	Water,
	Earth,
	Air	
};

UCLASS()
class UE_MULTIPLAYERTEMP_API UCustomGameplayAbility : public UObject //: public UGameplayAbility// : public UGameplayEffect
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
		int32 AbilityID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
		FString AbilityName;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Ability")
		class UGameplayAbility* GameplayAbility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
		TEnumAsByte<ElementType> ElementType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
		int32 AbilityLevel;


	//UPROPERTY(BlueprintEditAnywhere, Category = "Effects")
	//	class UGameplayEffect* GameplayEffects;

};
