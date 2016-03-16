// Fill out your copyright notice in the Description page of Project Settings.

#include "SeniorProject.h"
#include "MainCharacter.h"


// Sets default values
AMainCharacter::AMainCharacter()
{
	GetCapsuleComponent()->OnComponentHit.AddDynamic(this, &AMainCharacter::OnHit);
	GetCapsuleComponent()->BodyInstance.SetCollisionProfileName("Pawn");
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//GetCapsuleComponent()->SetNotifyRigidBodyCollision(true);
	
	PrimaryActorTick.bCanEverTick = true;
	cable = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cable"));
	cam = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	spring = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	box->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	movementComponent = (UCharacterMovementComponent*)GetComponentByClass(UCharacterMovementComponent::StaticClass());

	GetMesh()->SetRelativeLocation(FVector(0.f,0.f,-95.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, 0.f, -90.f));
	spring->SetRelativeRotation(FRotator(0.f, 0.f, 180.f));
	spring->TargetArmLength = 900.f;
	
	cable->AttachParent = GetMesh();
	spring->AttachParent = RootComponent;
	cam->AttachParent = spring;
	spring->bUsePawnControlRotation = false;

	playerMovementState = EPlayerState::E_Mobile;
	grabToSlideDelay = 0.25;


}

void AMainCharacter::OnConstruction(const FTransform& transform)
{

}

void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AMainCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FVector start = GetActorLocation();
	FVector end = start + ((float)1 * FVector(0.f, 50.f, 0.f));
	FHitResult outHit = FHitResult(ForceInit);
	FCollisionQueryParams params;
	params.bTraceComplex = false;
	params.AddIgnoredActor(this);
	

	switch (playerMovementState) 
	{
	case EPlayerState::E_Mobile:
		AddMovementInput(FVector(0.f, -1.f, 0.f), movementInput);
		break;
	case EPlayerState::E_WallGrab:
		if (movementInput == 0)
		{
			if (canSlide)
			{
				ChangePlayerState(EPlayerState::E_Mobile);
			}
			else
			{
				if (grabToSlideTime < grabToSlideDelay)
				{
					grabToSlideTime += DeltaTime;
				}
				else
				{
					canSlide = true;
					grabToSlideTime = 0.f;
				}
			}
		}
		else
		{
			canSlide = false;
			if (int(FMath::Sign(movementInput)) * -1 == wallJumpDir)
			{
				ChangePlayerState(EPlayerState::E_Mobile);
			}
			else
			{
				if (movementInput == 0)
				{

					if (GetWorld()->LineTraceSingleByChannel(outHit, start, end, ECollisionChannel::ECC_WorldStatic, params) && movementComponent->IsFalling())
					{
						if (outHit.GetActor())
						{
							bool implementsWallJump = false;
							auto comps = outHit.GetActor()->GetComponents();
							for (int i = 0; i < comps.Num(); i++)
							{
								implementsWallJump = comps[i]->GetClass()->ImplementsInterface(UWallJumpInterface::StaticClass()); //this seems excessive. look into component tags.
								if (implementsWallJump)
								{
									break;
								}
								else
								{
									ChangePlayerState(EPlayerState::E_Mobile);
								}
							}


							if (!implementsWallJump)
							{
								ChangePlayerState(EPlayerState::E_Mobile);
							}	
						}
					}
				}
				else
				{
					ChangePlayerState(EPlayerState::E_Mobile);
				}
			}
		}
		break;
	case EPlayerState::E_WallSlide:
		break;
	default:
		break;
	}

}

void AMainCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);
	InputComponent->BindAxis("AimUp", this, &AMainCharacter::AimUp);
	InputComponent->BindAxis("AimRight", this, &AMainCharacter::AimRight);
	InputComponent->BindAction("Jump", IE_Pressed, this, &AMainCharacter::TryJump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	InputComponent->BindAction("Grapple", IE_Pressed, this, &AMainCharacter::Grapple);
	//InputComponent->BindAction("Grapple", IE_Released, this, &AMainCharacter::StopGrapple);
}

void AMainCharacter::OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Hit.");
}

void AMainCharacter::AimUp(float axisValue)
{
	aimInput.Y = axisValue;
}

void AMainCharacter::AimRight(float axisValue)
{
	aimInput.X = axisValue;
}


void AMainCharacter::MoveRight(float axisValue)
{
	movementInput = axisValue;
}

bool AMainCharacter::ChangePlayerState(EPlayerState newState)
{
	return false;
}

void AMainCharacter::Grapple()
{
	GetGrappleLocation(aimInput);
}

void AMainCharacter::SetGrappleTarget_Implementation(AActor* grappledEntity)
{
	grappleTarget = grappleTarget;
	grappleLocation = grappleTarget->GetActorLocation();
}

FVector AMainCharacter::GetGrappleLocation_Implementation(FVector input)
{
	return FVector(0, 0, 0);
}

AActor* AMainCharacter::GetGrappleTarget_Implementation(FVector input)
{
	return nullptr;
}

bool AMainCharacter::Dash_Implementation()
{
	return false;
}

void AMainCharacter::TryJump()
{
	Jump();
	
	return;
}

bool AMainCharacter::AllowJump()
{
	return false;
}

void AMainCharacter::UpdateState()
{
	return;
}

bool AMainCharacter::StunAttack_Implementation()
{
	return false;
}

bool AMainCharacter::DeployShield_Implementation()
{
	return false;
}

bool AMainCharacter::SphereTrace(
	TArray<AActor*> ignoreList,
	const FVector& start,
	const FVector& end,
	const float radius,
	FHitResult& outHit,
	ECollisionChannel traceChannel,
	bool testSelf)
{
	bool result = false;
	FCollisionQueryParams trace(true);
	trace.bTraceComplex = true;
	trace.AddIgnoredActors(ignoreList);
	if (!testSelf)
		trace.AddIgnoredActor(this);
	outHit = FHitResult(ForceInit);
	TObjectIterator<APlayerController> pc;
	if (pc)
		return pc->GetWorld()->SweepSingle(outHit, start, end, FQuat(), traceChannel, FCollisionShape::MakeSphere(radius), trace);
	else
		return false;
}