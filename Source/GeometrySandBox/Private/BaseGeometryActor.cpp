// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All)

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMesh);

}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();//TODO


	//PrintStringTypes();
	//PrintTransform
}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector CurrentLocation = GetActorLocation();
	float time = GetWorld()->GetTimeSeconds();
	CurrentLocation.Z = InitialLocation.Z + Amplitude * FMath::Sin(Frequency * time);

	SetActorLocation(CurrentLocation);
	//printTypes();
}

void ABaseGeometryActor::PrintTransform() {

	FTransform Transform = GetActorTransform();//TODO
	FVector Location = Transform.GetLocation();//TODO
	FRotator Rotator = Transform.Rotator();
	FVector Scale = Transform.GetScale3D();

	UE_LOG(LogBaseGeometry, Warning, TEXT("Actor name %s"), *GetName());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Transform %s"), *Transform.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Location %s"), *Location.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Rotator %s"), *Rotator.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Scale %s"), *Scale.ToString());

	UE_LOG(LogBaseGeometry, Error, TEXT("Human Transform %s"), *Transform.ToHumanReadableString());


}

void ABaseGeometryActor::PrintStringTypes() {
	FString Name = "Alex Segeda";
	UE_LOG(LogBaseGeometry, Display, TEXT("NAME: %s"), *Name);

	FString WeaponsNumStr = "Weapons num = " + FString::FromInt(WeaponsNum);
	FString HealthStr = "Health = " + FString::SanitizeFloat(Health);
	FString IsDeadStr = "Is Dead = " + FString(IsDead ? "true" : "false");

	FString Stat = FString::Printf(TEXT("\nAll stat \n%s\n%s\n%s"), *WeaponsNumStr, *HealthStr, *IsDeadStr);
	UE_LOG(LogBaseGeometry, Warning, TEXT("%s"), *Stat);

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, Name);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Stat, true, FVector2D(1.5, 1.5));

}

void ABaseGeometryActor::printTypes()
{
	UE_LOG(LogTemp, Display, TEXT("Hello Unreal!"));
	UE_LOG(LogTemp, Warning, TEXT("Hello Unreal!"));
	UE_LOG(LogTemp, Error, TEXT("Hello Unreal!"));
	UE_LOG(LogTemp, Display, TEXT("Weapons num: %d, kills num: %i"), WeaponsNum, KillsNum);
	UE_LOG(LogTemp, Display, TEXT("Health num: %.2f"), Health);
	UE_LOG(LogTemp, Display, TEXT("IsDead num: %d"), IsDead);
	UE_LOG(LogTemp, Display, TEXT("HasWeapon num: %d"), static_cast<int>(HasWeapon));

}

