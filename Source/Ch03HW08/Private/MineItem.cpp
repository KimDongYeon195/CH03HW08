// Fill out your copyright notice in the Description page of Project Settings.


#include "MineItem.h"

AMineItem::AMineItem()
{
	ExplosionDelay = 5.f;
	ExplosionRadius = 300.f;
	Explosiondamage = 30.f;
	ItemType = "Mine";
}

void AMineItem::ActivateItem(AActor* Activator)
{
	//DestroyItem(); -> 즉발형이 아니기 때문에 일단 보류
	//지뢰를 사용했을때 로직 구현
	//간단히 즉발형으로 할 수도 있다.
	//지연시간, 폭발 범위등의 로직을 구현할 수도 있다.
	//폭발 이펙트(파티클), 사운드도 구현 가능
}

