
#include "MeleeEnemyBase.h"

// Sets default values
AMeleeEnemyBase::AMeleeEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	CollisionComponent->SetCollisionProfileName(TEXT("HitBox"));
	RootComponent = CollisionComponent;

	AttackRange = CreateDefaultSubobject<UBoxComponent>(TEXT("AttackRange"));
	AttackRange->SetCollisionProfileName(TEXT("AttackOverlapHitBox"));
	AttackRange->SetupAttachment(RootComponent);


	EnemyComponent = CreateDefaultSubobject<UEnemyComponent>(TEXT("Enemy Component"));
	EnemyComponent->bIsMelee = true;

}

// Called when the game starts or when spawned
void AMeleeEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	AttackRange->OnComponentBeginOverlap.AddDynamic(this, &AMeleeEnemyBase::OnOverlapBegin);
	AttackRange->OnComponentEndOverlap.AddDynamic(this, &AMeleeEnemyBase::OnOverlapEnd);
	TimeLeftForAttack = 0;
	EnemyComponent->bIsAttacking = false;
	
}

// Called every frame
void AMeleeEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (EnemyComponent->bIsAttacking)
	{
		if (TimeLeftForAttack <= 0)
		{
			Attack(PlayerRef);
			TimeLeftForAttack = (1 / EnemyComponent->AttackRate);
		}
	}
	TimeLeftForAttack -= DeltaTime;

}

// Called to bind functionality to input
void AMeleeEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMeleeEnemyBase::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor);
		if (Player)
		{
			PlayerRef = Player;
			EnemyComponent->bIsAttacking = true;
		}
	}
}

void  AMeleeEnemyBase::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	EnemyComponent->bIsAttacking = false;
}

void AMeleeEnemyBase::RecieveDamage(APlayerCharacter* Player, float Damage)
{
	if ( (EnemyComponent->Health) - Damage <= 0)
	{
		//kill actor
		Terminate();
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

void AMeleeEnemyBase::Attack(APlayerCharacter* Player)
{
	if (Player)
	{
		Player->RecieveDamage(EnemyComponent->Damage);
	}
}
