
// Fill out your copyright notice in the Description page of Project Settings.


//#include "AbilitySystem/GASAttributeSet.h"
#include "GASAttributeSet.h"
#include <Net/UnrealNetwork.h>
#include "AbilitySystemComponent.h"

UGASAttributeSet::UGASAttributeSet()
{

}

void UGASAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	// Replicate props
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Base Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Oxygen, COND_None, REPNOTIFY_Always);

	//DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, AttackPower, COND_None, REPNOTIFY_Always);

	// Player Attack / Defence Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, OverallDamageToDeal, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, OverallDamageToTake, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, PhysicalAttack, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MagicAttack, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, PhysicalDefence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, MagicDefence, COND_None, REPNOTIFY_Always);

	// Player Resistances
	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, FireResistance, COND_None, REPNOTIFY_Always);

}

void UGASAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	// Notify when attribute changes
	const auto PreviousValue = OldHealth.GetCurrentValue();
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Health, PreviousValue);
}

void UGASAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina)
{
	const auto PreviousValue = OldStamina.GetCurrentValue();
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Stamina, PreviousValue);
}

void UGASAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	const auto PreviousValue = OldMana.GetCurrentValue();
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Mana, PreviousValue);
}

void UGASAttributeSet::OnRep_Oxygen(const FGameplayAttributeData& OldOxygen)
{
	const auto PreviousValue = OldOxygen.GetCurrentValue();
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Oxygen, PreviousValue);
}

void UGASAttributeSet::OnRep_OverallDamageToDeal(const FGameplayAttributeData& OldOverallDamageToDeal)
{
	const auto PreviousValue = OldOverallDamageToDeal.GetCurrentValue();
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Oxygen, PreviousValue);
}

void UGASAttributeSet::OnRep_OverallDamageToTake(const FGameplayAttributeData& OldOverallDamageToTake)
{
	const auto PreviousValue = OldOverallDamageToTake.GetCurrentValue();
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, Oxygen, PreviousValue);
}

//void UGASAttributeSet::OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower)
//{
//	const auto PreviousValue = OldAttackPower.GetCurrentValue();
//	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, AttackPower, PreviousValue);
//}

void UGASAttributeSet::OnRep_PhysicalAttack(const FGameplayAttributeData& OldPhysicalAttack)
{
	const auto PreviousValue = OldPhysicalAttack.GetCurrentValue();
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, PhysicalAttack, PreviousValue);
}

void UGASAttributeSet::OnRep_MagicAttack(const FGameplayAttributeData& OldMagicAttack)
{
	const auto PreviousValue = OldMagicAttack.GetCurrentValue();
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MagicAttack, PreviousValue);
}

void UGASAttributeSet::OnRep_PhysicalDefence(const FGameplayAttributeData& OldPhysicalDefence)
{
	const auto PreviousValue = OldPhysicalDefence.GetCurrentValue();
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, PhysicalDefence, PreviousValue);
}

void UGASAttributeSet::OnRep_MagicDefence(const FGameplayAttributeData& OldMagicDefence)
{
	const auto PreviousValue = OldMagicDefence.GetCurrentValue();
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, MagicDefence, PreviousValue);
}

// Player Resistances

void UGASAttributeSet::OnRep_FireResistance(const FGameplayAttributeData& OldFireResistance)
{
	const auto PreviousValue = OldFireResistance.GetCurrentValue();
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, FireResistance, PreviousValue);
}

void UGASAttributeSet::OnRep_EarthResistance(const FGameplayAttributeData& OldEarthResistance)
{
	const auto PreviousValue = OldEarthResistance.GetCurrentValue();
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, EarthResistance, PreviousValue);
}

void UGASAttributeSet::OnRep_WaterResistance(const FGameplayAttributeData& OldWaterResistance)
{
	const auto PreviousValue = OldWaterResistance.GetCurrentValue();
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, WaterResistance, PreviousValue);
}

void UGASAttributeSet::OnRep_AirResistance(const FGameplayAttributeData& OldAirResistance)
{
	const auto PreviousValue = OldAirResistance.GetCurrentValue();
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, AirResistance, PreviousValue);
}

