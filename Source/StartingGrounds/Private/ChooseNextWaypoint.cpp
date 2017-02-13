// Fill out your copyright notice in the Description page of Project Settings.

#include "StartingGrounds.h"
#include "ChooseNextWaypoint.h"
#include "PatrolRoute.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"



EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{

	//auto PatrolRoute = ObjectInitializer.CreateDefaultSubObject<UChooseNextWaypoint>(this, TEXT("Patrol Route"));
	//get the patrol points

	//getting the ai controller
	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();

	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();


	//if(!ensure(PatrolRoute){ return ebtnoderesult::failed;}
	//cast the patrollingGuard to the controlled pawn or vice versa?
	//get the patrol points of the patrolling guard
	auto PatrolPoints = PatrolRoute->GetPatrolPoints();

	//if(PatrolPoints.Num() == 0){ ue log (" no patrol points")
//return failed};

	//sets next waypoint
	//get the blackboard component and get the value as an int for the index
	auto BlackboardComponent = OwnerComp.GetBlackboardComponent();
	//we're getting the value of a blackboardkey
	auto Index = BlackboardComponent->GetValueAsInt(IndexKey.SelectedKeyName);
	
	BlackboardComponent->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	//todo protect against empty control routes

	//UE_LOG(LogTemp, Warning, TEXT("Waypoint index: %i"), Index);

	//cycleindex

	// patrolpoints.num tells you the amount of index's in the array
	//next index is the index after the previous one
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	
	//increment the index of the array
	BlackboardComponent->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);
	//BlackboardComponent->SetValueAsInt(WaypointKey.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;

}

