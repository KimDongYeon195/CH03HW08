

#include "SpawnVolume.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"


ASpawnVolume::ASpawnVolume()
{
	PrimaryActorTick.bCanEverTick = false;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	SpawningBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawningBox"));
	SpawningBox->SetupAttachment(Scene);

	ItemDataTable = nullptr;
}

AActor* ASpawnVolume::SpawnRandomItem()
{
	if (FItemSpaewnRow* SelectedRow = GetRandomItem())
	{
		if (UClass* ActualClass = SelectedRow->ItemClass.Get())
		{
			return SpawnItem(ActualClass);
		}
	}

	return nullptr;
}

FVector ASpawnVolume::GetRandomPointInVolume() const
{
	FVector BoxExtent = SpawningBox->GetScaledBoxExtent();
		//GetScaledBoxExtent : 해당 컴포넌트의 3차원반지름(= 중심부터 끝거리)
	FVector BoxOrigin = SpawningBox->GetComponentLocation();
		//GetComponentLocation : 해당 컴포넌트의 중심좌표(컴포넌트는 볼륨의 중심으로 계산되기 떄문)

		//각 x y z 축별로 지정범위의 랜덤값을 가져옴
	return BoxOrigin + FVector(
		FMath::FRandRange(-BoxExtent.X, BoxExtent.X), //앞서 말했듯, 중심으로부터 계산
		FMath::FRandRange(-BoxExtent.Y, BoxExtent.Y), //ex) signed int를 예로 생각해보자
		FMath::FRandRange(-BoxExtent.Z, BoxExtent.Z)
	);
}

FItemSpaewnRow* ASpawnVolume::GetRandomItem() const
{
	if (!ItemDataTable) return nullptr;

	// 1) 모든 Row(행) 가져오기
	TArray<FItemSpaewnRow*> AllRows; //데이터 테이블의 모든 행을 가져오기위한 변수 선언
	
	//못가져온 행이있을때 알려주는 디버그 코드
	static const FString ContextString(TEXT("ItemSpawnContext")); 

	ItemDataTable->GetAllRows(ContextString, AllRows); 

	if (AllRows.IsEmpty()) return nullptr;

	// 2) 전체 확률 합 구하기
	float TotalChance = 0.0f; // 초기화
	for (const FItemSpaewnRow* Row : AllRows) // AllRows 배열의 각 Row를 순회
	{
		if (Row) // Row가 유효한지 확인
		{
			TotalChance += Row->SpawnChance; // SpawnChance 값을 TotalChance에 더하기
		}
	}

	// 3) 0 ~ TotalChance 사이 랜덤 값
	const float RandValue = FMath::FRandRange(0.0f, TotalChance);
	float AccumulateChance = 0.0f;

	// 4) 누적 확률로 아이템 선택
	for (FItemSpaewnRow* Row : AllRows)
	{
		AccumulateChance += Row->SpawnChance; //모든 확률을 하나씩 더해줌
		if (RandValue <= AccumulateChance) //뽑은 값이 누적된 값보다 작은가?
		{
			return Row; //그렇다면 값 반환
		}
	}

	return nullptr;
}
//아이템 스폰
AActor* ASpawnVolume::SpawnItem(TSubclassOf<AActor> ItemClass)
{
	if (!ItemClass) return nullptr;

	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>( //하위 클래스까지 적용 가능 -> 제일 큰 범위의 액터 지정
		ItemClass, // 해당 ~~의
		GetRandomPointInVolume(), // 랜덤위치에
		FRotator::ZeroRotator //회전은 X
	);
	return SpawnedActor;
}

