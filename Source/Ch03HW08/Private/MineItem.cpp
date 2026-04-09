// Fill out your copyright notice in the Description page of Project Settings.


#include "MineItem.h"
#include "Components/SphereComponent.h"

AMineItem::AMineItem()
{
	ExplosionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("ExplosionCollision"));
	ExplosionCollision->InitSphereRadius(300.f);
	ExplosionCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	ExplosionCollision->SetupAttachment(Scene);//루트컴포넌트에 붙이기

	ExplosionDelay = 5.f;
	ExplosionRadius = 300.f;
	Explosiondamage = 30;
	ItemType = "Mine";

}

void AMineItem::ActivateItem(AActor* Activator)
{
	GetWorld()->GetTimerManager().SetTimer(ExplosionTimerHandle, this, &AMineItem::Explode, ExplosionDelay, false);
}

void AMineItem::Explode()
{
	TArray<AActor*> OverlappingActors; //액터의 배열 생성
	ExplosionCollision->GetOverlappingActors(OverlappingActors); //액터 배열에 

	for (AActor* Actor : OverlappingActors)
	{
		if (Actor && Actor->ActorHasTag("Player"))
		{
			GEngine->AddOnScreenDebugMessage(
				-1, 
				2.f, 
				FColor::Red, 
				FString::Printf(TEXT("Player damaged %d by Mine!"), Explosiondamage));
		}
	}

	DestroyItem(); //-> 즉발형이 아니기 때문에 일단 보류
	//지뢰를 사용했을때 로직 구현
	//간단히 즉발형으로 할 수도 있다.
	//지연시간, 폭발 범위등의 로직을 구현할 수도 있다.
	//폭발 이펙트(파티클), 사운드도 구현 가능

}
