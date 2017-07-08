// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "BombBaseCPP.h"
#include "BombBase_CPP.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BombFactory_CPP.generated.h"

// Owner can register here to get informed when any bomb is destroyed
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAnyBombExplodedDelegate);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UBombFactory_CPP : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBombFactory_CPP();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
		void OnBombExploded()
	{
		UE_LOG(LogTemp, Warning, TEXT("Factory heard a bomb explode. Broadcasting..."));
		AnyBombExploded.Broadcast();
	}

	UFUNCTION(BlueprintCallable, Category = "Bombs")
		bool DropBomb(FVector position, int power, int blastRange, float detonationDelay);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TSubclassOf<ABombBase_CPP> MyBombType;

	UPROPERTY(BlueprintAssignable, Category = "Event Dispatchers")
		FAnyBombExplodedDelegate AnyBombExploded;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		APawn* Instigator;
};
