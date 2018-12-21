// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "ActorFactories/ActorFactoryBoxVolume.h"
#include "ActorFactoryLSystem.generated.h"


class AActor;
struct FAssetData;

UCLASS()
class TESTC_API UActorFactoryLSystem : public UActorFactoryBoxVolume
{

	GENERATED_UCLASS_BODY()

	//~ Begin UActorFactory Interface
	virtual bool PreSpawnActor(UObject* Asset, FTransform& InOutLocation);
	virtual bool CanCreateActorFrom( const FAssetData& AssetData, FText& OutErrorMsg ) override;
	virtual void PostSpawnActor( UObject* Asset, AActor* NewActor) override;
	virtual void PostCreateBlueprint( UObject* Asset, AActor* CDO ) override;
	virtual UObject* GetAssetFromActorInstance(AActor* ActorInstance) override;
	//~ End UActorFactory Interface
	
	
};
