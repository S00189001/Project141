
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

	DOREPLIFETIME_CONDITION_NOTIFY(UGASAttributeSet, Health, COND_None, REPNOTIFY_Always);

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

void UGASAttributeSet::OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower)
{
	const auto PreviousValue = OldAttackPower.GetCurrentValue();
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGASAttributeSet, AttackPower, PreviousValue);
}
