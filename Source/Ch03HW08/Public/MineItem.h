
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine");
	float Explosiondamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine");
	float ExplosionDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine");
	float ExplosionRadius;

	virtual void ActivateItem(AActor* Activator) override;
	
};
