// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_FindRandomPosition.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT3_API UBTTask_FindRandomPosition : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_FindRandomPosition();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
