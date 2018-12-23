// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LindemayerFoliageType.generated.h"


class UFoliageType;

UCLASS()
class ULindemayerFoliageType : public UObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ULindemayerFoliageType();

protected:
	

public:	
	UFoliageType* m_pFoliageType = nullptr;

	
	
};