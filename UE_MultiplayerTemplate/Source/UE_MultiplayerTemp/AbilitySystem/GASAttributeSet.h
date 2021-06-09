// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
//#include "UE_MultiplayerTemp/AbilitySystem/GASAttributeSet.h"
#include "AbilitySystemComponent.h"

#include "GASAttributeSet.generated.h"

// uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 *
 */
UCLASS()
class UE_MULTIPLAYERTEMP_API UGASAttributeSet : public UAttributeSet
{
	GENERATED_BODY()


public:

	UGASAttributeSet();

	//// Update properties for MP
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	//// Health Attribute
	UPROPERTY(BlueprintReadWrite, Category = "Attributes", ReplicatedUsing = OnRep_Health)		
		FGameplayAttributeData Health;	

	// Macro for getters / setters
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Health);

	UFUNCTION()
		virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	//// Stamina Attribute
	UPROPERTY(BlueprintReadWrite, Category = "Attributes", ReplicatedUsing = OnRep_Stamina)
		FGameplayAttributeData Stamina;

	// Macro for getters / setters
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Stamina);

	UFUNCTION()
		virtual void OnRep_Stamina(const FGameplayAttributeData& OldStamina);

	//// AttackPower Attribute
	UPROPERTY(BlueprintReadWrite, Category = "Attributes", ReplicatedUsing = OnRep_AttackPower)

		FGameplayAttributeData AttackPower;

	// Macro for getters / setters
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, AttackPower);

	UFUNCTION()
		virtual void OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower);


};
