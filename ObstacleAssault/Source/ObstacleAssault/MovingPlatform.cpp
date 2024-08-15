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
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime) // Update
{
	Super::Tick(DeltaTime);

	// Move platform forwards
	// get current location
	FVector currentLocation = GetActorLocation();
	// add vector to that location
	currentLocation += platformVelocity * DeltaTime;
	// set the location
	SetActorLocation(currentLocation);
	// move platform backwards if gone too far
	// check how far we've moved
	float distanceMoved = FVector::Dist(startLocation, currentLocation);
	// reverse direction of motion if gone too far
	if (distanceMoved > moveDistance)
	{
		platformVelocity = -platformVelocity;
		startLocation = currentLocation;
	}
}
