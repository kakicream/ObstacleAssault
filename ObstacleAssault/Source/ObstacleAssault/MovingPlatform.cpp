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
	if (ShouldPlatformReturn())
	{
		FVector moveDirection = platformVelocity.GetSafeNormal();
		startLocation = startLocation + moveDirection * moveDistance;
		SetActorLocation(startLocation);
		platformVelocity = -platformVelocity;
	}
	else
	{
		FVector currentLocation = GetActorLocation();
		currentLocation += platformVelocity * DeltaTime;
		SetActorLocation(currentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	// FRotator currentRotation = GetActorRotation();
	// currentRotation += ;
	// SetActorRotation(CurrentRotation);
	AddActorLocalRotation(rotationVelocity * DeltaTime);
}

// const keyword REQUIRED!
bool AMovingPlatform::ShouldPlatformReturn() const
{
	// moveDistance = 100 :
	// No being able to modify due to const
	// GetActorLocation();
	// Also impossible
	// How can we use GetDistanceMoved?
	return GetDistanceMoved() > moveDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(startLocation, GetActorLocation());
}