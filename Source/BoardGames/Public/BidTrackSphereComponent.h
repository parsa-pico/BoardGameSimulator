// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "BidTrackSphereComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BOARDGAMES_API UBidTrackSphereComponent : public USphereComponent
{
	GENERATED_BODY()

public:
	UBidTrackSphereComponent() ;

	// Example int variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BidTracking",Replicated)
	int32 BidValue = -1;
};
