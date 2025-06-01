// Fill out your copyright notice in the Description page of Project Settings.


#include "MeepleUtility.h"

void UMeepleUtility::ShiftActorArrayRight(TArray<AActor*>& ActorArray)
{
    if (ActorArray.Num() <= 1)
    {
        return;
    }

    AActor* Last = ActorArray.Last();

    for (int32 i = ActorArray.Num() - 1; i > 0; --i)
    {
        ActorArray[i] = ActorArray[i - 1];
    }

    ActorArray[0] = Last;
}
void UMeepleUtility::ShiftActorArrayLeft(TArray<AActor*>& ActorArray)
{
    if (ActorArray.Num() <= 1)
    {
        return;
    }

    AActor* First = ActorArray[0];

    for (int32 i = 0; i < ActorArray.Num() - 1; ++i)
    {
        ActorArray[i] = ActorArray[i + 1];
    }

    ActorArray[ActorArray.Num() - 1] = First;
}
