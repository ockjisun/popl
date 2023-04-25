// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatureAnimInstance.h"
#include "MyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


void UCreatureAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Creature = Cast<ACharacter>(Pawn);

		if (IsValid(Creature))
		{
			CharacterMovement = Creature->GetCharacterMovement();
		}
	}
}

void UCreatureAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (IsValid(Creature))
	{
		Velocity = CharacterMovement->Velocity;
		GroundSpeed = Velocity.Size2D();


		//auto Acceleration = CharacterMovement->GetCurrentAcceleration();
		//IsMoving = GroundSpeed > 3.0f && Acceleration != FVector::Zero();

		IsMoving = GroundSpeed > 3.0f;
		IsFalling = CharacterMovement->IsFalling();

	}
}

void UCreatureAnimInstance::PlayAttackMontage()
{
	if (IsValid(AttackMontage))
	{
		if (!Montage_IsPlaying(AttackMontage))
		{
			Montage_Play(AttackMontage, 1.f);
		}
	}
}
