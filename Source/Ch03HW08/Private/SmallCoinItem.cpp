

#include "SmallCoinItem.h"

ASmallCoinItem::ASmallCoinItem()
{
	PointValue = 10;
	ItemType = "SmallItem";
}

void ASmallCoinItem::ActivateItem(AActor* Activator)
{
	//DestroyItem();
	Super::ActivateItem(Activator);
}