// Fill out your copyright notice in the Description page of Project Settings.

#include "BombFactory_CPP.h"


// Sets default values for this component's properties
UBombFactory_CPP::UBombFactory_CPP()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBombFactory_CPP::BeginPlay()
{
	Super::BeginPlay();


}


// Called every frame
void UBombFactory_CPP::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


bool UBombFactory_CPP::DropBomb(FVector position, int power, int blastRange, float detonationDelayS)
{
	if ((power < 1) || (blastRange < 1) || (detonationDelayS <= 1))
	{
		UE_LOG(LogTemp, Warning, TEXT("Illegal Parameters @ UBombFactory_CPP::DropBomb()"));
		return false;
	}

	AActor* owner = GetOwner();
	UWorld* world = owner->GetWorld();

	// Old version of SpawnActorDeferred. Deprecated!
	//FRotator rotation = FRotator(0.0f);
	//ABombBaseCPP* bomb = world->SpawnActorDeferred<ABombBaseCPP>(MyBombType, position, rotation, GetOwner(), nullptr, true);

	// New Version. Takes Transform and CollisionHandlingMethod (Enum)
	FTransform transform(position);
	ESpawnActorCollisionHandlingMethod CollisionHandle = ESpawnActorCollisionHandlingMethod::AlwaysSpawn; //AdjustIfPossibleButAlwaysSpawn;
	ABombBase_CPP* bomb = world->SpawnActorDeferred<ABombBase_CPP>(MyBombType, transform, owner, nullptr, CollisionHandle);

	if ((!bomb) || (!bomb->IsValidLowLevel()))
	{
		UE_LOG(LogTemp, Warning, TEXT("Factory failed to spawn Bomb"));
		return false;
	}
	UE_LOG(LogTemp, Warning, TEXT("BombFactory succeeded at SpawnActorDeferred"));
	bomb->SetRange(blastRange);
	bomb->SetPower(power);
	bomb->SetDetonationDelay(detonationDelayS);
	bomb->FinishSpawning(transform, true);
	bomb->BombExploded.BindUObject(this, &UBombFactory_CPP::OnBombExploded);

	return true;
}