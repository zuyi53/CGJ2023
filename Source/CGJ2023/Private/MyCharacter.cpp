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
	UE_LOG(LogTemp, Warning, TEXT("This is the Character For Player %d"), PlayerIndex);
	
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

void AMyCharacter::Player1_MoveUp(float axisValue)
{
	this->AddMovementInput({ 1,0,0 }, axisValue, false);
	//UE_LOG(LogTemp, Log, TEXT("this is player 1"));
}

void AMyCharacter::Player1_MoveRight(float axisValue)
{
	this->AddMovementInput({ 0,1,0 }, axisValue, false);
	//UE_LOG(LogTemp, Log, TEXT("this is player 1"));
}

void AMyCharacter::Player2_MoveUp(float axisValue)
{

	UE_LOG(LogTemp, Log, TEXT("this is player 2"));
}

void AMyCharacter::Player2_MoveRight(float axisValue)
{
	UE_LOG(LogTemp, Log, TEXT("this is player 2"));
}

void AMyCharacter::Player3_MoveUp(float axisValue)
{
	UE_LOG(LogTemp, Log, TEXT("this is player 3"));
}

void AMyCharacter::Player3_MoveRight(float axisValue)
{
	UE_LOG(LogTemp, Log, TEXT("this is player 3"));
}

void AMyCharacter::Player4_MoveUp(float axisValue)
{
	UE_LOG(LogTemp, Log, TEXT("this is player 4"));
}

void AMyCharacter::Player4_MoveRight(float axisValue)
{
	UE_LOG(LogTemp, Log, TEXT("this is player 4"));
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//UGameplayStatics::GetPlayerControllerID(UGameplayStatics::GetPlayerController(GetWorld(),0)) ;

	if(PlayerIndex == 0)
	{
		InputComponent->BindAxis("Player1_MoveUp", this, &AMyCharacter::Player1_MoveUp);
		InputComponent->BindAxis("Player1_MoveRight", this, &AMyCharacter::Player1_MoveRight);
		InputComponent->BindAction("Player1_Interactive", EInputEvent::IE_Pressed,this, &AMyCharacter::Player1_Interactive);
		InputComponent->BindAction("Player1_Skill", EInputEvent::IE_Pressed, this, &AMyCharacter::Player1_Skill);
	//}
	//else if (PlayerIndex == 1)
	//{
		InputComponent->BindAxis("Player2_MoveUp", this, &AMyCharacter::Player1_MoveUp);
		InputComponent->BindAxis("Player2_MoveRight", this, &AMyCharacter::Player1_MoveRight);
		InputComponent->BindAction("Player2_Interactive", EInputEvent::IE_Pressed, this, &AMyCharacter::Player2_Interactive);
		InputComponent->BindAction("Player2_Skill", EInputEvent::IE_Pressed, this, &AMyCharacter::Player2_Skill);
	}




}

