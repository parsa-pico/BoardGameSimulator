// Fill out your copyright notice in the Description page of Project Settings.


#include "BidTrackSphereComponent.h"
#include "Net/UnrealNetwork.h"

void UBidTrackSphereComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UBidTrackSphereComponent, BidValue);
}

UBidTrackSphereComponent::UBidTrackSphereComponent()
{	SetIsReplicatedByDefault(true);
}
