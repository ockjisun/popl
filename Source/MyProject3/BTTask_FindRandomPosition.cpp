// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindRandomPosition.h"
#include "MyAIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"


UBTTask_FindRandomPosition::UBTTask_FindRandomPosition()
{
	NodeName = TEXT("FindRandomPosition");
}

EBTNodeResult::Type UBTTask_FindRandomPosition::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (CurrentPawn != nullptr)
	{
		UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
		if (NavSystem != nullptr)
		{
			FNavLocation RandomLocation;
			if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 500.f, RandomLocation))
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName(TEXT("RandomPosition")), RandomLocation.Location);
				return EBTNodeResult::Succeeded;
			}
		}
	}

	return EBTNodeResult::Failed;
}
