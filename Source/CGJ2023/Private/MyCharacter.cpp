// Fill out your copyright notice in the Description page of Project Settings.
#include "MyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	PrimaryActorTick.bCanEverTick = true;
	SetActorTickEnabled(true);


	static ConstructorHelpers::FObjectFinder<UStaticMesh> assetPlayer1(TEXT("StaticMesh'/Game/Mesh/player1.player1'"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> assetPlayer2(TEXT("StaticMesh'/Game/Mesh/player2.player2'"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> assetPlayer3(TEXT("StaticMesh'/Game/Mesh/player3.player3'"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> assetPlayer4(TEXT("StaticMesh'/Game/Mesh/player4.player4'"));

	CharacterImage = CreateDefaultSubobject<UStaticMeshComponent>("CharacterImage");
	CharacterImage->SetupAttachment(GetRootComponent());
	//EnableInput(GetWorld()->GetFirstPlayerController());
	SM_Player1 = assetPlayer1.Object;
	SM_Player2 = assetPlayer2.Object;
	SM_Player3 = assetPlayer3.Object;
	SM_Player4 = assetPlayer4.Object;
	CharacterImage->SetStaticMesh(SM_Player1);
	CharacterImage->SetRelativeRotation({0, 90, 0},false);	
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	
	Super::BeginPlay();
	

	UE_LOG(LogTemp, Warning, TEXT("eginPlay!!!!!!!!!! %d"), PlayerIndex);
}

// Called every frame
void AMyCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);	
	UE_LOG(LogTemp, Warning, TEXT("Character is ticking"));
}

void AMyCharacter::switchImage(int32 index)
{
	switch (index)
	{
	case 1:
		CharacterImage->SetStaticMesh(SM_Player1);
		break;
	case 2:
		CharacterImage->SetStaticMesh(SM_Player2);
		break;
	case 3:
		CharacterImage->SetStaticMesh(SM_Player3);
	case 4:
		CharacterImage->SetStaticMesh(SM_Player4);
		break;
	default:
		CharacterImage->SetStaticMesh(SM_Player1);
		break;		
	}
}


void AMyCharacter::Player1_Interactive()
{
	UE_LOG(LogTemp, Warning, TEXT("Player %d interactive button called"), PlayerIndex);
}

void AMyCharacter::Player1_Skill()
{
	UE_LOG(LogTemp, Warning, TEXT("Player %d skill button called"), PlayerIndex);
}

void AMyCharacter::Player2_Interactive()
{
	if (bEnablePickup)
	{
		
	}
	UE_LOG(LogTemp, Warning, TEXT("Player %d interactive button called"), PlayerIndex);
}

void AMyCharacter::Player2_Skill()
{
	UE_LOG(LogTemp, Warning, TEXT("Player %d skill button called"), PlayerIndex);
}

void AMyCharacter::Player3_Interactive()
{
	UE_LOG(LogTemp, Warning, TEXT("Player %d interactive button called"), PlayerIndex);
}

void AMyCharacter::Player3_Skill()
{
	UE_LOG(LogTemp, Warning, TEXT("Player %d skill button called"), PlayerIndex);
}

void AMyCharacter::Player4_Interactive()
{
	UE_LOG(LogTemp, Warning, TEXT("Player %d interactive button called"), PlayerIndex);
}

void AMyCharacter::Player4_Skill()
{
	UE_LOG(LogTemp, Warning, TEXT("Player %d skill button called"), PlayerIndex);
}

void AMyCharacter::Player1_MoveUp(float axisValue)
{	
	//AddMovementInput({ 10 * axisValue,0,0 }, false);
	AddActorLocalOffset({axisValue * speed, 0,0 }, false, false, ETeleportType::None);
}
	
void AMyCharacter::Player1_MoveRight(float axisValue)
{
	AddActorLocalOffset({ 0, axisValue * speed, 0 }, false, false, ETeleportType::ResetPhysics);
}

void AMyCharacter::Player2_MoveUp(float axisValue)
{
	if (PlayerChararcter_2_ref)
	{
		PlayerChararcter_2_ref->AddActorLocalOffset({ axisValue * speed, 0,0 }, false, false, ETeleportType::None);
	}
}

void AMyCharacter::Player2_MoveRight(float axisValue)
{
	if(PlayerChararcter_2_ref)
	{
		PlayerChararcter_2_ref->AddActorLocalOffset({ 0, axisValue * speed, 0 }, false, false, ETeleportType::None);
	}	
}

void AMyCharacter::Player3_MoveUp(float axisValue)
{
	if (PlayerChararcter_3_ref)
	{
		PlayerChararcter_3_ref->AddActorLocalOffset({ axisValue * speed, 0,0 }, false, false, ETeleportType::None);
	}
}

void AMyCharacter::Player3_MoveRight(float axisValue)
{
	if (PlayerChararcter_3_ref)
	{
		PlayerChararcter_3_ref->AddActorLocalOffset({ 0, axisValue * speed, 0 }, false, false, ETeleportType::None);
	}
}

void AMyCharacter::Player4_MoveUp(float axisValue)
{
	if (PlayerChararcter_4_ref)
	{
		PlayerChararcter_4_ref->AddActorLocalOffset({ axisValue * speed, 0,0 }, false, false, ETeleportType::None);
	}
}

void AMyCharacter::Player4_MoveRight(float axisValue)
{
	if (PlayerChararcter_4_ref)
	{
		PlayerChararcter_4_ref->AddActorLocalOffset({ 0, axisValue * speed, 0 }, false, false, ETeleportType::None);
	}
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//UE_LOG(LogTemp, Warning, TEXT("INITIAL CHARACTER INPUT "), PlayerIndex);

	InputComponent->BindAxis("Player1_MoveUp", this, &AMyCharacter::Player1_MoveUp);
	InputComponent->BindAxis("Player1_MoveRight", this, &AMyCharacter::Player1_MoveRight);
	InputComponent->BindAction("Player1_Interactive", IE_Pressed, this, &AMyCharacter::Player1_Interactive);
	InputComponent->BindAction("Player1_Skill", IE_Pressed, this, &AMyCharacter::Player1_Skill);

	InputComponent->BindAxis("Player2_MoveUp", this, &AMyCharacter::Player2_MoveUp);
	InputComponent->BindAxis("Player2_MoveRight", this, &AMyCharacter::Player2_MoveRight);
	InputComponent->BindAction("Player2_Interactive", IE_Pressed, this, &AMyCharacter::Player2_Interactive);
	InputComponent->BindAction("Player2_Skill", IE_Pressed, this, &AMyCharacter::Player2_Skill);

	InputComponent->BindAxis("Player3_MoveUp", this, &AMyCharacter::Player3_MoveUp);
	InputComponent->BindAxis("Player3_MoveRight", this, &AMyCharacter::Player3_MoveRight);
	InputComponent->BindAction("Player3_Interactive", IE_Pressed, this, &AMyCharacter::Player3_Interactive);
	InputComponent->BindAction("Player3_Skill", IE_Pressed, this, &AMyCharacter::Player3_Skill);

	InputComponent->BindAxis("Player4_MoveUp", this, &AMyCharacter::Player2_MoveUp);
	InputComponent->BindAxis("Player4_MoveRight", this, &AMyCharacter::Player2_MoveRight);
	InputComponent->BindAction("Player4_Interactive", IE_Pressed, this, &AMyCharacter::Player4_Interactive);
	InputComponent->BindAction("Player4_Skill", IE_Pressed, this, &AMyCharacter::Player4_Skill);

}




