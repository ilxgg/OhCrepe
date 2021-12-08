// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MeleeEnemyBase.h"
#include "Components\SphereComponent.h"
#include "MarshmellowEnemy.generated.h"


/**
 * 
 */
UCLASS()
class OHCREPE_API AMarshmellowEnemy : public AMeleeEnemyBase
{
	GENERATED_BODY()

		

public:

	AMarshmellowEnemy();


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USphereComponent* ExplosionRadius;
};
