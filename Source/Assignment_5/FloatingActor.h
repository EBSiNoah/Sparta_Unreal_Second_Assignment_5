// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

DECLARE_DELEGATE(FCustomEvent);

UCLASS()
class ASSIGNMENT_5_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();
	FCustomEvent OnEvent; 
	TArray<FVector> coordinates;
	int idx;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void EventHandler()
	{
		UE_LOG(LogTemp, Error, TEXT("Event occur"));
	}

	virtual int Step()
	{
		return FMath::RandRange(0, 1);
	}

	virtual float Distance(FVector before, FVector after)
	{
		float dx = before.X - after.X;
		float dy = before.Y - after.Y;
		return FMath::Sqrt(dx * dx + dy * dy);
	}

	virtual void Move()
	{
		
		FVector coordinate = GetActorLocation();
		
//		while (idx < 10)
//		{
			coordinate.X += Step();
			coordinate.Y += Step();
			SetActorLocation(coordinate);
			coordinates.Add(coordinate);
			UE_LOG(LogTemp, Warning, TEXT("Actor Location : x:%f, y:%f"), coordinates[idx].X, coordinates[idx].Y);
			if (idx <= 0)
			{
				UE_LOG(LogTemp, Warning, TEXT("Move distance : %f"), Distance(coordinates[idx], coordinates[idx]));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Move distance : %f"), Distance(coordinates[idx-1], coordinates[idx]));
			}
			if (Step())
			{
				OnEvent.ExecuteIfBound();
			}
//			idx++;
//		}
	}

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComponent;
};
