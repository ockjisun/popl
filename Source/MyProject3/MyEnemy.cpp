// Fill out your copyright notice in the Description page of Project Settings.


#include "MyEnemy.h"
#include "MyAIController.h"
#include "CreatureAnimInstance.h" 

// Sets default values
AMyEnemy::AMyEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonSevarog/Characters/Heroes/Sevarog/Meshes/Sevarog.Sevarog'"));

	if (SM.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));
	}

	AIControllerClass = AMyAIController::StaticClass();
}

// Called when the game starts or when spawned
void AMyEnemy::BeginPlay()
{
	Super::BeginPlay();

	AnimInstance = Cast<UCreatureAnimInstance>(GetMesh()->GetAnimInstance());
	AnimInstance->OnMontageEnded.AddDynamic(this, &AMyEnemy::OnAttackMontageEnded);
}

// Called every frame
void AMyEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyEnemy::Attack()
{
	
	if (IsValid(AnimInstance))
	{
		AnimInstance->PlayAttackMontage();
	}
}

void AMyEnemy::OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted)
{
	IsAttacking = false;

}

void AMyEnemy::OnHit()
{
	FHitResult HitResult;
	FCollisionQueryParams Parems(NAME_None, false, this);

	float AttackRange = 100.f;
	float AttackRadius = 50.f;


	FVector Center = GetActorLocation();
	FVector Forward = GetActorLocation() + GetActorForwardVector() * AttackRange;


	bool Result = GetWorld()->SweepSingleByChannel(
		OUT HitResult,
		Center,
		Forward,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(AttackRadius),
		Parems);

	float HalfHeight = AttackRange * 0.5f + AttackRadius;
	FQuat Rotation = FRotationMatrix::MakeFromZ(Forward).ToQuat();
	FColor DrawColor;

	if (Result && HitResult.GetActor())
	{
		DrawColor = FColor::Green;
	}
	else
	{
		DrawColor = FColor::Red;
	}


	DrawDebugCapsule(GetWorld(), Center, HalfHeight, AttackRadius, Rotation, DrawColor, false, 2.f);

	
}

