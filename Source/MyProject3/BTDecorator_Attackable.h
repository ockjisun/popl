// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_Attackable.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT3_API UBTDecorator_Attackable : public UBTDecorator
{
	GENERATED_BODY()
	UBTDecorator_Attackable();
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	
};
