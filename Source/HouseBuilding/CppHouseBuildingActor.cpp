// Fill out your copyright notice in the Description page of Project Settings.


#include "CppHouseBuildingActor.h"

// Sets default values
ACppHouseBuildingActor::ACppHouseBuildingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Build = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BuildMesh"));
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	RootComponent = Scene;

	Build->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACppHouseBuildingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACppHouseBuildingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!ACppHouseBuildingActor::bBuildingCompleted)
		ACppHouseBuildingActor::RotationObject();

	ACppHouseBuildingActor::bBuildingCompleted = ACppHouseBuildingActor::BuildingCompleted(0.1f);
}

bool ACppHouseBuildingActor::BuildingCompleted(float BuildingDeltaDuration)
{
	ACppHouseBuildingActor::CurrentTimeDuration = ACppHouseBuildingActor::BuildingDuration - BuildingDeltaDuration;
	ACppHouseBuildingActor::BuildingDuration = ACppHouseBuildingActor::CurrentTimeDuration;

	if (ACppHouseBuildingActor::CurrentTimeDuration <= 0)
		return true;
	else
		return false;
}

bool ACppHouseBuildingActor::ReturnBuildingCompleted()
{
	return ACppHouseBuildingActor::bBuildingCompleted;
}

float ACppHouseBuildingActor::ReturnCurrentDurationFromCompletedBuilding()
{
	return ACppHouseBuildingActor::CurrentTimeDuration;
}

void ACppHouseBuildingActor::RotationObject()
{
	Build->AddLocalRotation(FRotator(0.f, 1.f, 0.f), false);
}

