// Fill out your copyright notice in the Description page of Project Settings.


#include "HealingItem.h"

AHealingItem::AHealingItem()
{
	HealAmount = 20.f;
	ItemType = "Healing";
}

void AHealingItem::ActivateItem(AActor* Activator)
{
	//캐릭터 체력 회복 로직 구현
	DestroyItem();
}