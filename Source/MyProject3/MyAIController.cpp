// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

AMyAIController::AMyAIController()
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BT(TEXT("/Script/AIModule.BehaviorTree'/Game/AI/BT_Enemy.BT_Enemy'"));
	if (BT.Succeeded())
	{
		
		BehaviorTree = BT.Object;
	}
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BB(TEXT("/Script/AIModule.BlackboardData'/Game/AI/BB_Enemy.BB_Enemy'"));
	{
		
		BlackboardData = BB.Object;
	}
}

void AMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	auto BlackboardComponent = GetBlackboardComponent();

	if (UseBlackboard(BlackboardData, BlackboardComponent))
	{
		if (RunBehaviorTree(BehaviorTree))
		{
			UE_LOG(LogTemp, Log, TEXT("It Works"));
		}
	}
}

void AMyAIController::OnUnPossess()
{
	Super::OnUnPossess();
}
