
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpartaCharacter.generated.h"

class USpringArmComponent; 
class UCameraComponent; 
class UWidgetComponent;
struct FInputActionValue;


UCLASS()
class CH03HW08_API ASpartaCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASpartaCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	UWidgetComponent* OverheadWidget;

	// 현재 체력을 가져오는 함수
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealth() const;
	// 체력을 회복시키는 함수
	UFUNCTION(BlueprintCallable, Category = "Health")
	void AddHealth(float Amount);

protected:
	
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void Move(const FInputActionValue& value);

	UFUNCTION()
	void StartJump(const FInputActionValue& value);
	
	UFUNCTION()
	void StopJump(const FInputActionValue& value);
	
	UFUNCTION()
	void Look(const FInputActionValue& value);
	
	UFUNCTION()
	void StartSprint(const FInputActionValue& value);
	
	UFUNCTION()
	void StopSprint(const FInputActionValue& value);

	//최대 체력
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category =" Health")
	float MaxHealth;

	//현재 체력
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = " Health")
	float Health;

	// 데미지 처리 함수 - 외부로부터 데미지를 받을 때 호출됨
	// 또는 AActor의 TakeDamage()를 오버라이드
	virtual float TakeDamage(
		float DamageAmount,  //데미지 양
		struct FDamageEvent const& DamageEvent, //데미지 유형 
		AController* EventInstigator, //누가 데미지를 입혔냐
		AActor* DamageCauser //데미지 발생시킨 오브젝트(지뢰)
	) override;

	//체력 0일때 호출(사망)
	void OnDeath();
	void UpdateOverheadHP();

private:

	float NormalSpeed; 
	float SprintSpeedMultiplier;  
	float SprintSpeed; 	

};
