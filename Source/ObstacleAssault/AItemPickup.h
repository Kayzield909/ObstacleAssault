// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IAttackable.h"
#include "NiagaraComponent.h"
#include "Sound/SoundBase.h"
#include "AItemPickup.generated.h"

// Forward declaring our class
class UNiagaraSystem;

UCLASS()
class OBSTACLEASSAULT_API AAItemPickup : public AActor, public IIAttackable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAItemPickup();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere)
	FRotator RotationRate = FRotator(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	USoundBase* PickupSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	class UNiagaraSystem* PickupEffect;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Implementation of the attackable interface
	virtual void OnHitByWeapon_Implementation(AActor* Attacker) override;
	
	// Rotation function
	void RotateItem(float DeltaTime);

};
