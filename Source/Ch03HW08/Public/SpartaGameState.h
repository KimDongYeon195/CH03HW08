
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "SpartaGameState.generated.h"


UCLASS()
class CH03HW08_API ASpartaGameState : public AGameState
{
    GENERATED_BODY()

public:
    ASpartaGameState();

    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Score")
    int32 Score;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
    int32 SpawnedCoinCount;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
    int32 CollectedCoinCount;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
    float LevelDuration;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
    int32 CurrentLevelIndex;

    // 전체 레벨의 개수
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
    int32 MaxLevels;

    // 실제 레벨 맵 이름 배열. 여기 있는 인덱스를 차례대로 연동
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
    TArray<FName> LevelMapNames;

    // 매 레벨이 끝나기 전까지 시간이 흐르도록 관리하는 타이머
    FTimerHandle LevelTimerHandle;
    
    // 현재 점수를 읽는 함수
    UFUNCTION(BlueprintPure, Category = "Score")
    int32 GetScore() const;
    // 점수를 추가해주는 함수
    UFUNCTION(BlueprintCallable, Category = "Score")
    void AddScore(int32 Amount);

    // 게임이 완전히 끝났을 때 (모든 레벨 종료) 실행되는 함수
    UFUNCTION(BlueprintCallable, Category = "Level")
    void OnGameOver();

    void StartLevel();
    // 레벨 제한 시간이 만료되었을 때 호출
    void OnLevelTimeUp();
    // 코인을 주웠을 때 호출
    void OnCoinCollected();
    // 레벨을 강제 종료하고 다음 레벨로 이동
    void EndLevel();

};
