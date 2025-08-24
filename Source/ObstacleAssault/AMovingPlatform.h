// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AMovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AAMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	void MovePlatform(float DeltaTime);

	void RotatePlatform(float DeltaTime);
public:

	FVector StartLocation;

	UPROPERTY(VisibleAnywhere)
	float DistanceMoved;

	UPROPERTY(EditAnywhere)
	float MovementDistance = 100.0f;
	
	UPROPERTY(EditAnywhere)
	FVector PlatformVelocity = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere)
	FRotator PlatformRotationRate = FRotator(0.0f, 0.0f, 0.0f);
};
