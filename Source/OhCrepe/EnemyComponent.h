// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OHCREPE_API UEnemyComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemyComponent();

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Enemy Stats| Attacking")
		bool bIsMelee;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy Stats| Attacking")
		float AttackRate;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy Stats")
		float Health;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy Stats| Attacking")
		float Damage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy Stats")
		float Speed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy Stats")
		bool bIsElite;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy Stats| Elite Enemy Variables")
		float HealthMulti;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy Stats| Elite Enemy Variables")
		float DamageMulti;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy Stats| Elite Enemy Variables")
		float SpeedMulti;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
