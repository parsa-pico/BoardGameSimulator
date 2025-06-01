// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MeepleUtility.generated.h"

/**
 * 
 */
UCLASS()
class BOARDGAMES_API UMeepleUtility : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	/** Shifts an array of actors one position to the right (last becomes first). */
	UFUNCTION(BlueprintCallable, Category = "Meeple|Array")
	static void ShiftActorArrayRight(UPARAM(ref) TArray<AActor*>& ActorArray);
	UFUNCTION(BlueprintCallable, Category = "Meeple|Array")
	static void ShiftActorArrayLeft(UPARAM(ref) TArray<AActor*>& ActorArray);
};
