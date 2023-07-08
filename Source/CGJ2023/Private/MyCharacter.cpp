// Fill out your copyright notice in the Description page of Project Settings.
#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	static ConstructorHelpers::FObjectFinder<UStaticMesh> assetPlane(TEXT("StaticMesh'/Game/Mesh/myplane.myplane'"));
	CharacterImage = CreateDefaultSubobject<UStaticMeshComponent>("CharacterImage");
	CharacterImage->SetupAttachment(GetRootComponent());
	CharacterImage->SetStaticMesh(assetPlane.Object);
	CharacterImage->SetRelativeRotation({0, 90, 0},false);	


}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	//EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), PlayerIndex));
	//UE_LOG(LogTemp, Warning, TEXT("This is the Character For Player %d"), PlayerIndex);

}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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
	AddActorLocalOffset({axisValue * speed, 0,0 }, false, false, ETeleportType::None);
}
	
void AMyCharacter::Player1_MoveRight(float axisValue)
{
	AddActorLocalOffset({ 0, axisValue * speed, 0 }, false, false, ETeleportType::None);
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

	
		InputComponent->BindAxis("Player1_MoveUp", this, &AMyCharacter::Player1_MoveUp);
		InputComponent->BindAxis("Player1_MoveRight", this, &AMyCharacter::Player1_MoveRight);
		InputComponent->BindAction("Player1_Interactive", EInputEvent::IE_Pressed,this, &AMyCharacter::Player1_Interactive);
		InputComponent->BindAction("Player1_Skill", EInputEvent::IE_Pressed, this, &AMyCharacter::Player1_Skill);

		InputComponent->BindAxis("Player2_MoveUp", this, &AMyCharacter::Player2_MoveUp);
		InputComponent->BindAxis("Player2_MoveRight", this, &AMyCharacter::Player2_MoveRight);
		InputComponent->BindAction("Player2_Interactive", EInputEvent::IE_Pressed, this, &AMyCharacter::Player2_Interactive);
		InputComponent->BindAction("Player2_Skill", EInputEvent::IE_Pressed, this, &AMyCharacter::Player2_Skill);
	
		InputComponent->BindAxis("Player3_MoveUp", this, &AMyCharacter::Player3_MoveUp);
		InputComponent->BindAxis("Player3_MoveRight", this, &AMyCharacter::Player3_MoveRight);
		InputComponent->BindAction("Player3_Interactive", EInputEvent::IE_Pressed, this, &AMyCharacter::Player3_Interactive);
		InputComponent->BindAction("Player3_Skill", EInputEvent::IE_Pressed, this, &AMyCharacter::Player3_Skill);
	
		InputComponent->BindAxis("Player4_MoveUp", this, &AMyCharacter::Player2_MoveUp);
		InputComponent->BindAxis("Player4_MoveRight", this, &AMyCharacter::Player2_MoveRight);
		InputComponent->BindAction("Player4_Interactive", EInputEvent::IE_Pressed, this, &AMyCharacter::Player4_Interactive);
		InputComponent->BindAction("Player4_Skill", EInputEvent::IE_Pressed, this, &AMyCharacter::Player4_Skill);
}




