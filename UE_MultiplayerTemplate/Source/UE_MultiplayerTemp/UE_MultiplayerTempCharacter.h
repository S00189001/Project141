// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/DataTable.h"
#include "AbilitySystemInterface.h"
#include <GameplayEffectTypes.h>

#include "UE_MultiplayerTempCharacter.generated.h"

USTRUCT(BlueprintType)
struct FCraftingInfo : public FTableRowBase
{
	GENERATED_BODY();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CraftingInfo")
	FName ComponentID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CraftingInfo")
	FName ProductID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CraftingInfo")
	bool bDestroyItemA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CraftingInfo")
	bool bDestroyItemB;

};

USTRUCT(BlueprintType)
struct FInvetoryItem : public FTableRowBase
{

	GENERATED_BODY()

public:

	FInvetoryItem()
	{

		Name = FText::FromString("Item");
		Action = FText::FromString("Use");
		Description = FText::FromString("Enter A Description");
		Value = 1; //value of item 

	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InvetorySystem")
	FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InvetorySystem")
	TSubclassOf<class APickup> ItemPickup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InvetorySystem")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InvetorySystem")
	FText Action;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InvetorySystem")
	int32 Value;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InvetorySystem")
	UTexture2D* Thumbnail;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InvetorySystem")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InvetorySystem")
	TArray<FCraftingInfo> CraftCombinations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InvetorySystem")
	bool bCanBeUsed;

	bool operator==(const FInvetoryItem& Item) const  // overloading the = operator cause C++ cant compare Invetory items
	{
		if (ItemID == Item.ItemID)
			return true;
		else return false;
		
	}
};

UCLASS(config=Game)
class AUE_MultiplayerTempCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	// Add Ability System Comps
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UGASAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
		class UGASAttributeSet* Attributes;

public:
	AUE_MultiplayerTempCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	// Function for Ability System
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void InitializeAttributes();
	virtual void GiveAbilities();

	// Called on the server
	virtual void PossessedBy(AController* NewController) override;
	// Called on the client
	virtual void OnRep_PlayerState()override;

	// Effect that initializes our default attributes
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GAS")
		TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	// Effect that initializes our default Abilities
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GAS")
		TArray<TSubclassOf<class UGASGameplayAbility>> DefaultAbilities;



protected:

	void CheckForInteractables();

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

