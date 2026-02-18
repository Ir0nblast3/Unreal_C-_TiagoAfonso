// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDistanceMeter.h"
#include "MyCharacter.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UMyDistanceMeter::NativeConstruct()
{
	Super::NativeConstruct();

	ACharacter* Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (Character)
	{
		MyCharacter = Cast<AMyCharacter>(Character);
	}
}
void UMyDistanceMeter::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	if (MyCharacter)
	{
		UpdateDistance(MyCharacter->DistanceTravelled);
	}
}

void UMyDistanceMeter::UpdateDistance(float NewDistance)
{
	if (DistanceText)
	{
		DistanceText->SetText(FText::AsNumber(NewDistance));
	}
}