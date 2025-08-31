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

	float GetDistanceMoved();

	FVector2D GetEllipticalPosition(FVector2D InCentre, FVector2D InLength, float InTime);
	FVector SetEllipticalPosition(FVector2D InCentre, FVector2D InLength, float InTime);

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

	// Elliptical Orbit
	UPROPERTY(EditAnywhere)
	bool bFollowsEllipticalPath;
	UPROPERTY(EditAnywhere)
	float Time_t = 0.0f;
	UPROPERTY(EditAnywhere)
	float DeltaTime_t = 1.0f;

	UPROPERTY(EditAnywhere)
	FVector2D Centre_h_k = FVector2D (0.0f, 0.0f);
	UPROPERTY(EditAnywhere)
	FVector2D Length_a_b = FVector2D(100.0f, 50.0f);
};
