// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyActorComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT3_API UMyActorComponent : public UActorComponent
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, Category = Info, Meta = (AllowprivateAccess = true))
		int32 Level;
	UPROPERTY(EditAnywhere, Category = Info, Meta = (AllowprivateAccess = true))
		int32 HP;

public:	
	// Sets default values for this component's properties
	UMyActorComponent();

protected:
	virtual void InitializeComponent() override;
	virtual void BeginPlay() override;

public:	
	void SetLevel(int32 NewLevel);
	void OnDamaged(float DamageAmount);

	int32 GetLevel() { return Level; }
	int32 GetHP() { return HP; }
};
