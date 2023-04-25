// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CreatureAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT3_API UCreatureAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
protected:
	UPROPERTY(Category = Animation, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float GroundSpeed;
	UPROPERTY(Category = Animation, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float Horizontal;
	UPROPERTY(Category = Animation, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float Vertical;


	UPROPERTY(Category = Animation, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		FVector Velocity;
	UPROPERTY(Category = Animation, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		bool IsMoving;
	UPROPERTY(Category = Animation, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		bool IsFalling;

	UPROPERTY(Category = Animation, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UAnimMontage* AttackMontage;

	UPROPERTY(VisibleAnywhere)
		class ACharacter* Creature;
	UPROPERTY(VisibleAnywhere)
		class UCharacterMovementComponent* CharacterMovement;

public:
	UCreatureAnimInstance() = default;

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
public:
	void PlayAttackMontage();
	
};
