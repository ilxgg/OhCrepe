#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/BoxComponent.h"
#include "OhCrepe/EnemyComponent.h"
#include "OhCrepe/PlayerCharacter.h"
#include "MeleeEnemyBase.generated.h"


UCLASS()
class OHCREPE_API AMeleeEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMeleeEnemyBase();

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UEnemyComponent* EnemyComponent;


	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UBoxComponent* CollisionComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UBoxComponent* AttackRange;

	APlayerCharacter* PlayerRef;

	float TimeLeftForAttack;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Attack(APlayerCharacter* Player);

	void RecieveDamage(APlayerCharacter* Player, float Damage);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	virtual void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	virtual void Terminate();

};
