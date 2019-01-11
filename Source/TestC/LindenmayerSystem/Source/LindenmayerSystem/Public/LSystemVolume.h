// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "GameFramework/Volume.h"
#include "InstancedLSystemFoliage.h"
#include "LSystemFoliage.h"
#include "LandscapeComponent.h"
#include "LSystemVolume.generated.h"



/**
 * 
 */
struct FDesiredLSysInstance;
class ULSystemComponent;

// Number of buckets for layer weight histogram distribution.
#define NUM_INSTANCE_BUCKETS 10

UCLASS()
class ALSystemVolume : public AVolume
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(Category = Lindenmayer, VisibleAnywhere, BlueprintReadOnly)
	ULSystemComponent* LSystemComponent;

#if WITH_EDITOR
	
	void SpawnLSystemInstances(const TArray<FDesiredLSysInstance>& desiredInsts);
	void SpawnLSystemInstance(const ULSystemFoliageType* Settings, const FLSysFoliageInstance& Instance, const FLSysPotentialInstance& desiredInst);

	virtual void Destroyed() override;

	TArray<ALSystemFoliage*>& GetFoliage() {return FoliageActors;};

private:

	typedef TMap<FName, TMap<ULandscapeComponent*, TArray<uint8> > > LandscapeLayerCacheData;

	void CalculatePotentialInstances(const ULSystemFoliageType* Settings, const TArray<FDesiredLSysInstance>& DesiredInstances, TArray<FLSysPotentialInstance> OutPotentialInstances[NUM_INSTANCE_BUCKETS], LandscapeLayerCacheData* LandscapeLayerCachesPtr = nullptr);
	void CalculatePotentialInstances_ThreadSafe(const ULSystemFoliageType* Settings, const TArray<FDesiredLSysInstance>& DesiredInstances, TArray<FLSysPotentialInstance> OutPotentialInstances[NUM_INSTANCE_BUCKETS], const int32 StartIdx, const int32 LastIdx);

	bool CheckLocationForPotentialInstance(const UWorld* InWorld, const ULSystemFoliageType* Settings, const FVector& Location, const FVector& Normal, TArray<FVector>& PotentialInstanceLocations, FLSysFoliageInstanceHash& PotentialInstanceHash);
	void AddInstances(const ULSystemFoliageType* Settings, const TArray<FDesiredLSysInstance>& DesiredInstances,const TArray<int32>& ExistingInstanceBuckets, const float Pressure = 1.0f, LandscapeLayerCacheData* LandscapeLayerCachesPtr = nullptr);
	void AddInstance(ALSystemFoliage* LSA);

	
public:
	UPROPERTY()
	TArray<ALSystemFoliage*> FoliageActors;


	// UObject interface
	virtual void PostEditImport() override;

	virtual bool GetReferencedContentObjects(TArray<UObject*>& Objects) const override;
#endif
};