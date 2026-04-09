// Fill out your copyright notice in the Description page of Project Settings.


#include "BigCoinItem.h"

ABigCoinItem::ABigCoinItem()
{ 
	PointValue = 50;
	ItemType = "BigCoin";
}

//BigCoin을 획득하면 코인이 사라짐
void ABigCoinItem::ActivateItem(AActor* Activator)
{ 
	DestroyItem(); //BaseItem.h의 DestroyItem()함수 호출
}


