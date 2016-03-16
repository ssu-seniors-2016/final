// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "WallJumpInterface.h"
#include "MainCharacter.generated.h"

UENUM(BlueprintType)
enum class EPlayerState : uint8
{
	E_Mobile		UMETA(DisplayName = "Mobile"),
	E_WallGrab		UMETA(DisplayName = "Wall Grab"),
	E_WallSlide		UMETA(DisplayName = "Wall Slide"),
	E_GrapplePull	UMETA(DisplayName = "Pulled by Grapple"),
	E_GrappleHang	UMETA(DisplayName = "Hanging on Grapple")
};

UCLASS()		
class SENIORPROJECT_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMainCharacter();
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaSeconds ) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	virtual void OnConstruction(const FTransform& transform) ;

	UFUNCTION(BlueprintCallable, Category = "Main Character")
	bool ChangePlayerState(EPlayerState newState);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Main Character")
	FVector GetGrappleLocation(FVector input);
	FVector GetGrappleLocation_Implementation(FVector input);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Main Character")
	AActor* GetGrappleTarget(FVector input);
	AActor* GetGrappleTarget_Implementation(FVector input);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Main Character")
	void SetGrappleTarget(AActor* grappledEntity);
	void SetGrappleTarget_Implementation(AActor* grappledEntity);
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Main Character")
	bool Dash();
	bool Dash_Implementation();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Main Character")
	bool DeployShield();
	bool DeployShield_Implementation();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Main Character")
	bool StunAttack();
	bool StunAttack_Implementation();
	UFUNCTION(BlueprintCallable, Category = "Main Character")
	bool AllowJump();
	bool SphereTrace(	TArray<AActor*> ignoreList, 
						const FVector& start, 
						const FVector& end, 
						const float radius, 
						FHitResult& outHit, 
						ECollisionChannel traceChannel = ECC_WorldDynamic, 
						bool testSelf = false); //I can't believe I had to write this. Everything else you wrote for me, Epic, but not this?


	UPROPERTY(BlueprintReadWrite, Category = "Wall Jump")
	int32 wallJumpDir;
	UPROPERTY(BlueprintReadWrite, Category = "Wall Jump")
	bool canSlide;
	UPROPERTY(BlueprintReadWrite, Category = "Shield")
	bool isShieldSpawned;
	UPROPERTY(BlueprintReadWrite, Category = "Wall Jump")
	float wallSlideSpeed;
	UPROPERTY(BlueprintReadWrite, Category = "Wall Jump")
	float grabToSlideTime;
	UPROPERTY(BlueprintReadWrite, Category = "Movement")
	float defaultGravScale;
	UPROPERTY(BlueprintReadWrite, Category = "Dash")
	float dashTimer;
	UPROPERTY(BlueprintReadWrite, Category = "Stun")
	float stunTimer;
	UPROPERTY(BlueprintReadWrite, Category = "Grapple")
	AActor* grappleTarget;
	UPROPERTY(BlueprintReadWrite, Category = "Grapple")
	FVector grappleLocation;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* cable;
	UPROPERTY(EditAnywhere)
	USpringArmComponent* spring;
	UPROPERTY(EditAnywhere)
	UCameraComponent* cam;
	UPROPERTY(EditAnywhere)
	UBoxComponent* box;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Enum)
	EPlayerState playerMovementState;
	
	UFUNCTION()
	void OnHit(AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	


private:
	void UpdateState();
	void AimUp(float axisValue);
	void AimRight(float axisValue);
	void MoveRight(float axisValue);
	void TryJump();
	void Grapple();
	//void StopGrapple();
	UCharacterMovementComponent* movementComponent;
	FVector aimInput;
	float movementInput;
	float grabToSlideDelay;
	
	

};
