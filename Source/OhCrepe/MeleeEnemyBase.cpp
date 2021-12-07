// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeEnemyBase.h"

// Sets default values
AMeleeEnemyBase::AMeleeEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	EnemyComponent = CreateDefaultSubobject<UEnemyComponent>(TEXT("Enemy Component"));
	EnemyComponent->bIsMelee = true;

}

// Called when the game starts or when spawned
void AMeleeEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMeleeEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMeleeEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMeleeEnemyBase::RecieveDamage(float Damage)
{
	if ( (EnemyComponent->Health) - Damage <= 0)
	{
		//kill actor
		Destroy();
	}
	else
	{
		EnemyComponent->Health -= Damage;
	}
}

void AMeleeEnemyBase::Terminate()
{
	//do something before dying

	Destroy();
}

void AMeleeEnemyBase::Attack(AActor* Actor, float Damage)
{
	if (Actor)
	{

	}
}
