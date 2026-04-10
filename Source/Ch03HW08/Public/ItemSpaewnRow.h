
#pragma once

#include "CoreMinimal.h"
#include "ItemSpaewnRow.generated.h"


USTRUCT(BlueprintType)
struct FItemSpaewnRow : public FTableRowBase
{
	GENERATED_BODY()
public:
    //아이템 이름
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName ItemName;
    
    // 어떤 아이템 클래스를 스폰할지(BP or C++)
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<AActor> ItemClass; 
        //하드레퍼런스 기능
        //클래스를 참조하기위한 템플릿 구조
    
    // 이 아이템의 스폰 확률
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float SpawnChance;
};
