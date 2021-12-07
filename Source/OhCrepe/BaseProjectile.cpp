


#include "BaseProjectile.h"
#include "PlayerCharacter.h"
#include "MeleeEnemyBase.h"
#include "Engine\BlockingVolume.h"

// Sets default values
ABaseProjectile::ABaseProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Defines collision capsule and sets it as a child of root component
	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Capsule"));
	RootComponent = CollisionComponent;




	//Defines the static mesh variable so that a static mesh can be applied within a blueprint and sets as child of root component
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMesh->SetupAttachment(RootComponent);

	//Adds projectile movement component
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));

	ProjectileMovement->ProjectileGravityScale = 0.f;
	ProjectileMovement->InitialSpeed = InitSpeed;

	if (bCanBounce)
	{
		ProjectileMovement->bShouldBounce = true;
		ProjectileMovement->Bounciness = 100.f;

	}

}

// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ABaseProjectile::OnOverlapBegin);
	
}

// Called every frame
void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseProjectile::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void ABaseProjectile::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		
		
		if (!bIsFromPlayer)
		{
			APlayerCharacter* Character = Cast<APlayerCharacter>(OtherActor);
			if (Character)
			{
				Character->RecieveDamage(Damage);
			}
		}
		else if (bIsFromPlayer)
		{
			AMeleeEnemyBase* MeleeEnemy = Cast<AMeleeEnemyBase>(OtherActor);
			if (MeleeEnemy)
			{
				MeleeEnemy->RecieveDamage(Damage);
			}
		}

		ABlockingVolume* BlockingVolume = Cast<ABlockingVolume>(OtherActor);
		if (BlockingVolume)
		{
			Terminate();
		}
	}
}

void ABaseProjectile::Terminate()
{
	//can add fancy particle effects later 

	//Destroys Actor
	Destroy();
}