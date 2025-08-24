// Fill out your copyright notice in the Description page of Project Settings.


#include "AMovingPlatform.h"

// Sets default values
AAMovingPlatform::AAMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void MyTestFunction(float Parameter1, int Parameter2)
{
	UE_LOG(LogTemp, Display, TEXT("This is a test function.\nParameter 1 = %f\nParameter 2 = %d"), Parameter1, Parameter2);
}

// Called when the game starts or when spawned
void AAMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	
}

// Called every frame
void AAMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	SetActorLocation(StartLocation);
	StartLocation.Z++; //Increase Z position by 1 each frame
	*/

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
	
}

void AAMovingPlatform::MovePlatform(float DeltaTime)
{
	// Moves platform in X, Y or Z at PlatformVelocity cm/s
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);

	DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	if(DistanceMoved >= MovementDistance) // Reverses platform direction while fixing overshoot
	{
		PlatformVelocity = -PlatformVelocity;
		
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		FVector TargetLocation = StartLocation + MoveDirection * MovementDistance;
		SetActorLocation(TargetLocation);
		StartLocation = TargetLocation;
	}
}

void AAMovingPlatform::RotatePlatform(float DeltaTime)
{
	// Rotates platform in X, Y or Z at PlatformRotationRate deg/s
	FRotator CurrentRotation = GetActorRotation();
	CurrentRotation = CurrentRotation + (PlatformRotationRate * DeltaTime);
	SetActorRotation(CurrentRotation);
}