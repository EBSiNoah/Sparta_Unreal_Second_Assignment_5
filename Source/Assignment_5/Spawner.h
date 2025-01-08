// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FloatingActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class ASSIGNMENT_5_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SpawnFloatingActor()
	{
		FVector SpawnLocation = FVector(0.0f, 0.0f, 0.0f);
		FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		AFloatingActor* ActorToSpawn = GetWorld()->SpawnActor<AFloatingActor>(AFloatingActor::StaticClass(), SpawnLocation, SpawnRotation, SpawnParams);

		if (ActorToSpawn)
		{
			UE_LOG(LogTemp, Log, TEXT("Spawned at %s"), *SpawnLocation.ToString());
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Fail to spawn"));
		}
	}
};
