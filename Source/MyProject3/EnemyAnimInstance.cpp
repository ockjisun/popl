// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAnimInstance.h"

UEnemyAnimInstance::UEnemyAnimInstance()
{
	ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("/Script/Engine.AnimMontage'/Game/ParagonSevarog/Characters/Heroes/Sevarog/Animations/Swing1_Medium_Montage.Swing1_Medium_Montage'"));
	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}
}
