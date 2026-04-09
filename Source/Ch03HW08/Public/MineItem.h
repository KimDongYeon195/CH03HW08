
#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "MineItem.generated.h"

UCLASS()
class CH03HW08_API AMineItem : public ABaseItem
{
	GENERATED_BODY()
public:
	AMineItem();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|Mine");
	USphereComponent* ExplosionCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine");
	int32 Explosiondamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine");
	float ExplosionDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine");
	float ExplosionRadius;

	FTimerHandle ExplosionTimerHandle;

	virtual void ActivateItem(AActor* Activator) override;

	void Explode();
	
};
