// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorComponent.h"
#include "MyGameInstance.h"
#include "kismet/GameplayStatics.h"

UMyActorComponent::UMyActorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bWantsInitializeComponent = true;
	Level = 1;
}


void UMyActorComponent::InitializeComponent()
{
	Super::InitializeComponent();
	SetLevel(Level);
}


void UMyActorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UMyActorComponent::SetLevel(int32 NewLevel)
{
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (MyGameInstance)
	{
		auto CharacterData = MyGameInstance->GetCharacterData(NewLevel);
		{
			Level = CharacterData->Level;
			HP = CharacterData->MaxHP;
		}
	}
}

void UMyActorComponent::OnDamaged(float DamageAmount)
{
	HP -= DamageAmount;
	if (HP < 0)
	{
		HP = 0;
	}

	UE_LOG(LogTemp, Warning, TEXT("HP : %d"), HP);
}


