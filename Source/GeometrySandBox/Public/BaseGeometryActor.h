// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"

#include "BaseGeometryActor.generated.h"


UCLASS()
class GEOMETRYSANDBOX_API ABaseGeometryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseGeometryActor();
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* BaseMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere, Category = "Movement")
		float Amplitude = 50.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float Frequency = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	int32 WeaponsNum = 4;
	UPROPERTY(EditDefaultsOnly)
	int32 KillsNum = 7;
	UPROPERTY(EditInstanceOnly)
	float Health = 24.234f;
	UPROPERTY(EditAnywhere)
	bool IsDead = false;
	UPROPERTY(VisibleAnywhere)
	bool HasWeapon = true;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector InitialLocation;

	void printTypes();
	void PrintStringTypes();
	void PrintTransform();
};
