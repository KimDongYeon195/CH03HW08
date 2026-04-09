// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ItemInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI) //리플렉션을 위한 인터페이스
class UItemInterface : public UInterface
{
	GENERATED_BODY()
};

//실제 C++레벨에서 사용할 함수시그니처 정의
class CH03HW08_API IItemInterface //직접 구현하는 클래스
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//지뢰 힐링 코인
	//힐링 코인 -> 즉시 발동(오버랩 직후)

	UFUNCTION()
	virtual void OnItemOverlap(
		UPrimitiveComponent* OverlappedComp, //콜리전하는 본인컴포넌트(아이템)
		AActor* OtherActor, //콜리전하는 상대액터(플레이어)
		UPrimitiveComponent* OtherComp, //이 액터에 있는 충돌원인 액터(여기는 캡슐컴포넌트)
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) = 0;
	//아이템 범위 in
	//매개변수자료형을 왜 AActor? -> 오버랩이 사람이 될 수도, 드론, 몬스터, 펫;... 많으니까 가장큰 범위를 가져다 놓고 그떄그때 캐스팅만 해서 호출
	
	UFUNCTION()
	virtual void OnItemEndOverlap(
		UPrimitiveComponent* OverlappedComp, //콜리전하는 본인컴포넌트(아이템)
		AActor* OtherActor, //콜리전하는 상대액터(플레이어)
		UPrimitiveComponent* OtherComp, //이 액터에 있는 충돌원인 액터(여기는 캡슐컴포넌트)
		int32 OtherBodyIndex) = 0; //아이템 범위 out
	
	virtual void ActivateItem(AActor* Activator) = 0;
		//아이템 사용시
	
	virtual FName GetItemType() const = 0; 
	//FString대신 FName?? -> 내용은 같지만 단순히 이름같은 것만 찾아서 바로 반환할 때 FName이 메모리나 연산속도가 훨신 빠르다.
};	//아이템의 유형을 반환(Coin, Healing, Mine...)
