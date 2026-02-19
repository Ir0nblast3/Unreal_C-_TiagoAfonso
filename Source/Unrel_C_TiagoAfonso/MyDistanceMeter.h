// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyDistanceMeter.generated.h"

/**
 * 
 */
UCLASS()
class UNREL_C_TIAGOAFONSO_API UMyDistanceMeter : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

public:
	UPROPERTY(BlueprintReadWrite, Category="Distance")
	class AMyCharacter* MyCharacter = nullptr;
	
	UFUNCTION(BlueprintCallable, Category="Distance")
	void UpdateDistance(float NewDistance);

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* DistanceText = nullptr;

};
