// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"//SpringArm 사용하기 위해
#include "Camera/CameraComponent.h"//Camera 사용하기 위해
#include "Components/CapsuleComponent.h"//CapsuleComponent 사용하기 위해 
#include "CreatureAnimInstance.h"   //CreatureAnimInstance 사용하기 위해
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/WidgetComponent.h"
#include "MyPlayerWidget.h"
#include "MyActorComponent.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyActorComponent = CreateDefaultSubobject<UMyActorComponent>(TEXT("MyActor"));

	HpBaR = CreateDefaultSubobject<UWidgetComponent>(TEXT("HpBaR"));
	HpBaR->SetupAttachment(GetMesh());
	HpBaR->SetWidgetSpace(EWidgetSpace::Screen);
	static ConstructorHelpers::FClassFinder<UUserWidget> UW(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/WBP_PlayerBar.WBP_PlayerBar'"));
	if (UW.Succeeded())
	{
		HpBaR->SetWidgetClass(UW.Class);
		HpBaR->SetDrawSize(FVector2D(500.f, 80.f));
		HpBaR->SetRelativeLocation(FVector(0.f, 0.f, 200.f));
	}

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 500.f;
	SpringArm->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonShinbi/Characters/Heroes/Shinbi/Meshes/Shinbi.Shinbi'"));

	if (SM.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));
	}
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyCharacter::KeyUpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyCharacter::KeyLeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookLeftRight"), this, &AMyCharacter::LookLeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookUpDown"), this, &AMyCharacter::LookUpDown);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AMyCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Attack"), IE_Pressed, this, &AMyCharacter::Attack);
	PlayerInputComponent->BindAction(TEXT("BeginSprint"), IE_Pressed, this, &AMyCharacter::BeginSprint);
	PlayerInputComponent->BindAction(TEXT("EndSprint"), IE_Pressed, this, &AMyCharacter::EndSprint);
	PlayerInputComponent->BindAction(TEXT("BeginCrouch"), IE_Pressed, this, &AMyCharacter::BeginCrouch);
	PlayerInputComponent->BindAction(TEXT("EndCrouch"), IE_Pressed, this, &AMyCharacter::EndCrouch);
}

void AMyCharacter::KeyUpDown(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

void AMyCharacter::KeyLeftRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}

void AMyCharacter::LookLeftRight(float value)
{
	AddControllerYawInput(value);
}

void AMyCharacter::LookUpDown(float value)
{
	AddControllerPitchInput(value);
}

void AMyCharacter::Attack()
{
	
	auto AnimInstance = Cast<UCreatureAnimInstance>(GetMesh()->GetAnimInstance());
	if (IsValid(AnimInstance))
	{
		AnimInstance->PlayAttackMontage();
	}
}

void AMyCharacter::BeginSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 1000.0f;
}

void AMyCharacter::EndSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
}

void AMyCharacter::BeginCrouch()
{
	Crouch();
}

void AMyCharacter::EndCrouch()
{
	UnCrouch();
}









