// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyDistanceMeter.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class UNREL_C_TIAGOAFONSO_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame

	//virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
	float MovementSpeed = 1000.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
	float LaneOffSet = 200.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
	int32 CurrentLane = 0;

	UFUNCTION(BlueprintCallable, Category="Movement")
	void MoveLeft();

	UFUNCTION(BlueprintCallable, Category="Movement")
	void MoveRight();

	UFUNCTION(BlueprintCallable, Category="Movement")
	void RunForward();

	UFUNCTION(BlueprintCallable, Category="Movement")
	void UpdateLanePosition();

	UPROPERTY(EditAnywhere, Category="UI")
	TSubclassOf<UMyDistanceMeter> DistanceWidgetClass;

	UMyDistanceMeter* DistanceWidget;

	UPROPERTY(BlueprintReadWrite, Category="Distance")
	int32 DistanceTravelled;

	UPROPERTY(BlueprintReadOnly)
	FVector StartLocation;

	UFUNCTION(BlueprintCallable, Category="Distance")
	void UpdateTravelledDistance();
	

};
