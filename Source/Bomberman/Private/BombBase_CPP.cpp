// Fill out your copyright notice in the Description page of Project Settings.

#include "BombBase_CPP.h"


// Sets default values
ABombBase_CPP::ABombBase_CPP()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABombBase_CPP::BeginPlay()
{
	Super::BeginPlay();

}

void ABombBase_CPP::EndPlay(EEndPlayReason::Type reason)
{
	BombExploded.ExecuteIfBound();
}

// Called every frame
void ABombBase_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//DetonationDelaySec -= DeltaTime;
	//// Time is up. Destroy!
	//if (DetonationDelaySec <= 0)
	//	this->MarkPendingKill();
}

