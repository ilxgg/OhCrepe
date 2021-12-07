// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "BaseProjectile.generated.h"

UCLASS()
class OHCREPE_API ABaseProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseProjectile();

	/*Default Collision Component used for projectile hitbox*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBoxComponent* CollisionComponent;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Projectile Stats")
		float InitSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Projectile Stats")
		bool bCanBounce;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Projectile Stats")
		int NumberOfBounces;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Projectile Stats")
		float Damage;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Projectile Stats")
		bool bIsFromPlayer;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	virtual void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void Terminate();
};
