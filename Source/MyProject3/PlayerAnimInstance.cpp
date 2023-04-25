// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimInstance.h"

UPlayerAnimInstance::UPlayerAnimInstance()
{
	ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("/Script/Engine.AnimMontage'/Game/ParagonShinbi/Characters/Heroes/Shinbi/Animations/PrimaryMelee_D_Slow_Montage.PrimaryMelee_D_Slow_Montage'"));
	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}
}
