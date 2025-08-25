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
	
	if (bFollowsEllipticalPath == true)
	{
		SetEllipticalPosition(Centre_h_k, Length_a_b, Time_t);
	}
}

// Called every frame
void AAMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	SetActorLocation(StartLocation);
	StartLocation.Z++; //Increase Z position by 1 each frame
	*/

	
	RotatePlatform(DeltaTime);

	if (bFollowsEllipticalPath == false)
	{
		MovePlatform(DeltaTime);
	}
	else
	{
		Time_t = Time_t + (DeltaTime_t * DeltaTime);
		SetEllipticalPosition(Centre_h_k, Length_a_b, Time_t);
	}
}

void AAMovingPlatform::MovePlatform(float DeltaTime)
{

	DistanceMoved = GetDistanceMoved();
	
	if(DistanceMoved >= MovementDistance) // Reverses platform direction while fixing overshoot
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		FVector TargetLocation = StartLocation + MoveDirection * MovementDistance;
		SetActorLocation(TargetLocation);
		StartLocation = TargetLocation;

		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		// Moves platform in X, Y or Z at PlatformVelocity cm/s
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		SetActorLocation(CurrentLocation);
	}
}

void AAMovingPlatform::RotatePlatform(float DeltaTime)
{
	// Rotates platform in X, Y or Z at PlatformRotationRate deg/s
	FRotator CurrentRotation = GetActorRotation();
	CurrentRotation = CurrentRotation + (PlatformRotationRate * DeltaTime);
	SetActorRotation(CurrentRotation);
}

float AAMovingPlatform::GetDistanceMoved()
{
	FVector CurrentLocation = GetActorLocation();
	DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

	return DistanceMoved;
}

FVector AAMovingPlatform::SetEllipticalPosition(FVector2D Centre_h_k, FVector2D Length_a_b, float Time_t)
{
	FVector2D NewEllipticalPosition = GetEllipticalPosition(Centre_h_k, Length_a_b, Time_t);
	FVector NewEllipticalPos3D(NewEllipticalPosition.X, NewEllipticalPosition.Y, GetActorLocation().Z);
	SetActorLocation(NewEllipticalPos3D);
	return FVector();
}

FVector2D AAMovingPlatform::GetEllipticalPosition(FVector2D Centre_h_k, FVector2D Length_a_b, float Time_t)
{
	float x = Centre_h_k.X + Length_a_b.X * cos(Time_t);
	float y = Centre_h_k.Y + Length_a_b.Y * sin(Time_t);

	return FVector2D(x,y);
}
