// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Iteminterface.h"
#include "BaseItem.generated.h"

class USphereComponent;

UCLASS()
class CH03HW08_API ABaseItem : public AActor, public IItemInterface
{
	GENERATED_BODY()
	
public:	
	ABaseItem();

protected:
	virtual void OnItemOverlap(AActor* OverlapActor) override;

	virtual void OnItemEndOverlap(AActor* OverlapActor) override; 

	virtual void ActivateItem(AActor* Activator) override;

	virtual FName GetItemType() const override;

	virtual void DestroyItem();

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Item");
	FName ItemType;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Item|Component");
	



};
