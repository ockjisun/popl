// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class MYPROJECT3_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
		class UMyActorComponent* MyActorComponent;
	UPROPERTY(VisibleAnywhere)
		class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere)
		class UWidgetComponent* HpBaR;

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void KeyUpDown(float value);
	void KeyLeftRight(float value);
	void LookLeftRight(float value);
	void LookUpDown(float value);
	void Attack();
	void BeginSprint();
	void EndSprint();
	void BeginCrouch();
	void EndCrouch();


};
