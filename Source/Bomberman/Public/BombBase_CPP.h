// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BombBase_CPP.generated.h"

DECLARE_DELEGATE(FBombExplodedDelegate);

UCLASS(abstract)
class BOMBERMAN_API ABombBase_CPP : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABombBase_CPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type reason) override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FBombExplodedDelegate BombExploded;

#pragma region GETTERS AND SETTERS
	void SetDetonationDelay(float value)
	{
		DetonationDelaySec = value;
	}

	float GetDetonationDelay()
	{
		return DetonationDelaySec;
	}

	void SetPower(float value)
	{
		Power = value;
	}

	void SetRange(int value)
	{
		Range = value;
	}

#pragma endregion

protected:

	// Will be used when scaling becomes a thing
	// e.g.: Bombs have different time delays and character can scale
	//UPROPERTY(BlueprintReadWrite, EditAnywhere)
	//	float DetonationDelayScale;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int Power = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int Range = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float DetonationDelaySec = 3.0f;
};
