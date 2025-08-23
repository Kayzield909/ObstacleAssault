// Fill out your copyright notice in the Description page of Project Settings.


#include "ALearningVariablesAndOperators.h"

// Sets default values
AALearningVariablesAndOperators::AALearningVariablesAndOperators()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AALearningVariablesAndOperators::BeginPlay()
{
	Super::BeginPlay();
	
	/*
	//Declaring variables and assigning values
	bool bAlive = true;
	int Age = 27;
	char FirstInitial = 'k';
	float Height = 175.8f;
	double Pie = 3.141592653589793;
	FString CharName = "Kennedy";
	*/

	/* Logging Variables
	UE_LOG(LogTemp, Display, TEXT("Basic Log Message"));

	UE_LOG(LogTemp, Display, TEXT("It is %s I am alive."), (bAlive ? TEXT("true") : TEXT("false"))); // Argument to convert bool to string

	UE_LOG(LogTemp, Display, TEXT("I am %d years old."), Age);

	UE_LOG(LogTemp, Display, TEXT("My initial is %c."), FirstInitial);

	UE_LOG(LogTemp, Display, TEXT("I am %.2fcm tall."), Height);

	UE_LOG(LogTemp, Display, TEXT("Pi not pie equals %f"), Pie);

	UE_LOG(LogTemp, Display, TEXT("Oh, I forgot to mention my name is %s"), *CharName); //* special operator to convert to ue5 specific format
	*/

	// Number operators
	/*
	int LifeTimesLived;
	LifeTimesLived = Age / 4;

	UE_LOG(LogTemp, Display, TEXT("LifeTimesLived = %d"), LifeTimesLived);
	*/

	UE_LOG(LogTemp, Display, TEXT("New Player Spawned.\nName: %s\nAge: %d\nWeight: %f"), *PlayerName, Age, Weight);
}

// Called every frame
void AALearningVariablesAndOperators::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

