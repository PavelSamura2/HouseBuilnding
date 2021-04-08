// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppHouseBuildingActor.generated.h"

UCLASS()
class HOUSEBUILDING_API ACppHouseBuildingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppHouseBuildingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
		UStaticMeshComponent* Build;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
		USceneComponent* Scene;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default params")
	float CurrentTimeDuration = 0.01;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default params")
		float BuildingDuration = 200;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default params")
		float CurrentBuildingResource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default params")
		float BuildingResourceMAX = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default params")
		bool bBuildingCompleted;

	bool BuildingCompleted(float BuildingDeltaDuration);
	
	UFUNCTION(BlueprintCallable)
		bool ReturnBuildingCompleted();

	UFUNCTION(BlueprintCallable)
		float ReturnCurrentDurationFromCompletedBuilding();

	void RotationObject();
};
