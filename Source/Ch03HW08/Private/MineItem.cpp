// Fill out your copyright notice in the Description page of Project Settings.


#include "MineItem.h"
#include "Components/SphereComponent.h"
#include "Kismet/Gameplaystatics.h"
#include "Particles/ParticleSystemComponent.h"

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
	bHasExploded = false;

}

void AMineItem::ActivateItem(AActor* Activator)
{
	if (bHasExploded) return;

	Super::ActivateItem(Activator);

	GetWorld()->GetTimerManager().SetTimer(
		ExplosionTimerHandle,
		this,
		&AMineItem::Explode,
		ExplosionDelay,
		false
	);

	bHasExploded = true;
}

void AMineItem::Explode()
{
	UParticleSystemComponent* Particle = nullptr;

	if (ExplosionParticle)
	{
		Particle = UGameplayStatics::SpawnEmitterAtLocation(
			GetWorld(),
			ExplosionParticle,
			GetActorLocation(),
			GetActorRotation(),
			false
		);
	}


	if (ExplosionSound)
	{
		UGameplayStatics::PlaySoundAtLocation(
			GetWorld(),
			ExplosionSound,
			GetActorLocation()
		);
	}

	TArray<AActor*> OverlappingActors; //액터의 배열 생성
	ExplosionCollision->GetOverlappingActors(OverlappingActors); //액터 배열에 

	for (AActor* Actor : OverlappingActors)
	{
		if (Actor && Actor->ActorHasTag("Player"))
		{
			UGameplayStatics::ApplyDamage(
				Actor, //데미지 받은 액터
				Explosiondamage, //데미지 양
				nullptr, //데미지 유발 주체
				this,//데미지 유발 오브젝트
				UDamageType::StaticClass() //기본데미지 유형
			);
		}
	}

	DestroyItem(); 
	//지뢰를 사용했을때 로직 구현
	//간단히 즉발형으로 할 수도 있다.
	//지연시간, 폭발 범위등의 로직을 구현할 수도 있다.
	//폭발 이펙트(파티클), 사운드도 구현 가능

	if (Particle)
	{
		FTimerHandle DestroyParticleTimerHandle;
		
		GetWorld()->GetTimerManager().SetTimer(
			DestroyParticleTimerHandle,
			[Particle]()
			{
				if (Particle)
				{
					Particle->DestroyComponent();
				}
			},
			2.0f,
			false
		);
	}
}
