// Fill out your copyright notice in the Description page of Project Settings.


#include "AItemPickup.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"

// Sets default values
AAItemPickup::AAItemPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot")); // Create a scene comp and set as root
	RootComponent = SceneRoot;

	MeshComponent = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent); // Attachs Mesh to Scene Root

	// Setup collision to be detected by our trace
	MeshComponent->SetCollisionObjectType(ECC_WorldDynamic);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshComponent->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

// Called when the game starts or when spawned
void AAItemPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAItemPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	RotateItem(DeltaTime);

}


void AAItemPickup::OnHitByWeapon_Implementation(AActor* Attacker)
{
	// Play sound and particle effects at the items's location
	if (PickupSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, PickupSound, GetActorLocation());
	}
	if (PickupEffect)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, PickupEffect, GetActorLocation());
	}

	// Destroy the item
	Destroy();
}



void AAItemPickup::RotateItem(float DeltaTime)
{
	AddActorLocalRotation(RotationRate * DeltaTime);
}

