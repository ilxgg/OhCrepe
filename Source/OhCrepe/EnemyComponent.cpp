// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyComponent.h"

// Sets default values for this component's properties
UEnemyComponent::UEnemyComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	Health = 100;
	Damage = 1.f;
	Speed = 600.f;
	AttackRate = 1.f;

	HealthMulti = 1.5f;
	DamageMulti = 1.f;
	SpeedMulti = 1.3f;

	bIsElite = false;
	bIsMelee = true;


	if(bIsElite)
	{
		Health *= HealthMulti;
		Damage *= DamageMulti;
		Speed *= SpeedMulti;
	}
}


// Called when the game starts
void UEnemyComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEnemyComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

