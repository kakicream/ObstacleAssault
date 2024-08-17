// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay() // Start
{
	Super::BeginPlay();
	startLocation = GetActorLocation();

	FString myActorName = GetName();
	UE_LOG(LogTemp, Display, TEXT("BeginPlay : %s"), *myActorName);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime) // Update
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector currentLocation = GetActorLocation();
	currentLocation += platformVelocity * DeltaTime;
	SetActorLocation(currentLocation);

	float distanceMoved = FVector::Dist(startLocation, currentLocation);
	if (distanceMoved > moveDistance)
	{
		float overShoot = distanceMoved - moveDistance;
		FString myTestName = GetName();
		UE_LOG(LogTemp, Display, TEXT("MyTest : %f by %s"), overShoot, *myTestName);
		FVector moveDirection = platformVelocity.GetSafeNormal();
		startLocation = startLocation + moveDirection * moveDistance;
		SetActorLocation(startLocation);
		platformVelocity = -platformVelocity;
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
UE_LOG(LogTemp, Display, TEXT("Rotating"));
}
