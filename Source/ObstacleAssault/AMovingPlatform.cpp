// Fill out your copyright notice in the Description page of Project Settings.


#include "AMovingPlatform.h"

// Sets default values
AAMovingPlatform::AAMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	// SetActorLocation(StartLocation);
	
}

// Called every frame
void AAMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	SetActorLocation(StartLocation);
	StartLocation.Z++; //Increase Z position by 1 each frame
	*/

	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);

}

