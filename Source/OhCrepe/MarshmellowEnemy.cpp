// Fill out your copyright notice in the Description page of Project Settings.


#include "MarshmellowEnemy.h"

AMarshmellowEnemy::AMarshmellowEnemy()
{
	ExplosionRadius = CreateDefaultSubobject<USphereComponent>(TEXT("Explosion Radius"));
	ExplosionRadius->SetupAttachment(RootComponent);
	
}