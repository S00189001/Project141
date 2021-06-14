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

	//// Mana Attribute
	UPROPERTY(BlueprintReadWrite, Category = "Attributes", ReplicatedUsing = OnRep_Mana)
		FGameplayAttributeData Mana;

	// Macro for getters / setters
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, Mana);

	UFUNCTION()
		virtual void OnRep_Mana(const FGameplayAttributeData& OldMana);

	//// AttackPower Attribute
	UPROPERTY(BlueprintReadWrite, Category = "Attributes", ReplicatedUsing = OnRep_AttackPower)

		FGameplayAttributeData AttackPower;

	// Macro for getters / setters
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, AttackPower);

	UFUNCTION()
		virtual void OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower);

	//// Physical Attack Attribute
	UPROPERTY(BlueprintReadWrite, Category = "Attributes", ReplicatedUsing = OnRep_PhysicalAttack)

		FGameplayAttributeData PhysicalAttack;

	// Macro for getters / setters
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, PhysicalAttack);

	UFUNCTION()
		virtual void OnRep_PhysicalAttack(const FGameplayAttributeData& OldPhysicalAttack);

	//// Magic Attack Attribute
	UPROPERTY(BlueprintReadWrite, Category = "Attributes", ReplicatedUsing = OnRep_MagicAttack)

		FGameplayAttributeData MagicAttack;

	// Macro for getters / setters
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MagicAttack);

	UFUNCTION()
		virtual void OnRep_MagicAttack(const FGameplayAttributeData& OldMagicAttack);

	//// Physical Defence Attribute
	UPROPERTY(BlueprintReadWrite, Category = "Attributes", ReplicatedUsing = OnRep_PhysicalDefence)

		FGameplayAttributeData PhysicalDefence;

	// Macro for getters / setters
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, PhysicalDefence);

	UFUNCTION()
		virtual void OnRep_PhysicalDefence(const FGameplayAttributeData& OldPhysicalDefence);

	//// Magic Defence Attribute
	UPROPERTY(BlueprintReadWrite, Category = "Attributes", ReplicatedUsing = OnRep_MagicDefence)

		FGameplayAttributeData MagicDefence;

	// Macro for getters / setters
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, MagicDefence);

	UFUNCTION()
		virtual void OnRep_MagicDefence(const FGameplayAttributeData& OldMagicDefence);

	// Player Resistances

		//// Fire Resistance Attribute
	UPROPERTY(BlueprintReadWrite, Category = "Attributes", ReplicatedUsing = OnRep_FireResistance)

		FGameplayAttributeData FireResistance;

	// Macro for getters / setters
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, FireResistance);

	UFUNCTION()
		virtual void OnRep_FireResistance(const FGameplayAttributeData& OldFireResistance);

	//// Earth Resistance Attribute
	UPROPERTY(BlueprintReadWrite, Category = "Attributes", ReplicatedUsing = OnRep_EarthResistance)

		FGameplayAttributeData EarthResistance;

	// Macro for getters / setters
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, EarthResistance);

	UFUNCTION()
		virtual void OnRep_EarthResistance(const FGameplayAttributeData& OldEarthResistance);

	//// Water Resistance Attribute
	UPROPERTY(BlueprintReadWrite, Category = "Attributes", ReplicatedUsing = OnRep_WaterResistance)

		FGameplayAttributeData WaterResistance;

	// Macro for getters / setters
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, WaterResistance);

	UFUNCTION()
		virtual void OnRep_WaterResistance(const FGameplayAttributeData& OldWaterResistance);

	//// Air Resistance Attribute
	UPROPERTY(BlueprintReadWrite, Category = "Attributes", ReplicatedUsing = OnRep_AirResistance)

		FGameplayAttributeData AirResistance;

	// Macro for getters / setters
	ATTRIBUTE_ACCESSORS(UGASAttributeSet, AirResistance);

	UFUNCTION()
		virtual void OnRep_AirResistance(const FGameplayAttributeData& OldAirResistance);


};
