// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Blueprint/UserWidget.h"
#include "MyDistanceMeter.h"       
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

void AMyCharacter::RunForward()
{
	AddMovementInput(FVector::ForwardVector, MovementSpeed);
}

void AMyCharacter::MoveRight()
{
	CurrentLane ++;
	CurrentLane = FMath::Clamp(CurrentLane, -1, 1);
	UE_LOG(LogTemp, Warning, TEXT("%i"), CurrentLane);
	UpdateLanePosition();
}

void AMyCharacter::MoveLeft()
{
	CurrentLane --;
	CurrentLane = FMath::Clamp(CurrentLane, -1, 1);
	UpdateLanePosition();
}

void AMyCharacter:: UpdateLanePosition()
{
	float DeltaTime = GetWorld()->GetDeltaSeconds();
	FVector Location = GetActorLocation();
	float TargetY = CurrentLane * LaneOffSet;
	//Location.Y = CurrentLane * LaneOffSet;
	Location.Y = FMath::FInterpTo(Location.Y, TargetY,DeltaTime, 8.f);

	SetActorLocation(Location);
}

void AMyCharacter::UpdateTravelledDistance()
{
	DistanceTravelled = GetActorLocation().X; //- StartLocation.X;
	//DistanceTravelled = FMath::Max(0,
		//FMath::FloorToInt((GetActorLocation().X - StartLocation.X) / 100.f)
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

