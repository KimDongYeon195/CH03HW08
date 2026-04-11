
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
	
	virtual void ActivateItem(AActor* Activator) override;

	virtual FName GetItemType() const override;

	virtual void DestroyItem();

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Item");
	FName ItemType;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Item|Component");
	USceneComponent* Scene;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Item|Component");
	USphereComponent* Collision;
	
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Item|Component");
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Effects")
	UParticleSystem* PickupParticle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Effects")
	USoundBase* PickupSound;

	virtual void OnItemOverlap(
		UPrimitiveComponent* OverlappedComp, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) override;

	
	virtual void OnItemEndOverlap(
		UPrimitiveComponent* OverlappedComp, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex) override;
};
