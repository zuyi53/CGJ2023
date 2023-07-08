// Copyright Epic Games, Inc. All Rights Reserved.


#include "CGJ2023GameModeBase.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraActor.h"



ACGJ2023GameModeBase::ACGJ2023GameModeBase()
{
	DefaultPawnClass = AMyCharacter::StaticClass();

	const TCHAR* pathUI = (TEXT("WidgetBlueprint'/Game/Widget/W_FirstpersonHUD.W_FirstpersonHUD_C'"));

	static ConstructorHelpers::FClassFinder<UUserWidget>Find_WB_PlayerMain(pathUI);

	if (Find_WB_PlayerMain.Succeeded()) {
		WB_PlayerUI = Find_WB_PlayerMain.Class;
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("Fail to find wb"));
	}

}

ACGJ2023GameModeBase::~ACGJ2023GameModeBase()
{
}

void ACGJ2023GameModeBase::StartPlay()
{

	UE_LOG(LogTemp, Log, TEXT("GameMode Load"));
 	
	//Find Camera
	CameraActorClass = ACameraActor::StaticClass();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), CameraActorClass, MainCameraList );
	if (!MainCameraList.IsEmpty())
	{
		MainCameraRef = Cast<ACameraActor>(MainCameraList[0]);
	}	
	FActorSpawnParameters para1;

	PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerControllerRef)
	{		
		FVector PlayerStartLocation_1 = FindPlayerStart(PlayerControllerRef, "Player1")->GetActorLocation();
		//PlayerChararcter_1 = GetWorld()->SpawnActor<AMyCharacter>(PlayerStartLocation_1, {0,-90,0}, para1);
		PlayerChararcter_1 = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		PlayerChararcter_1->PlayerIndex = 0;
		PlayerChararcter_1->switchImage(1);
		PlayerControllerRef->Possess(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));	
		UE_LOG(LogTemp, Warning, TEXT("Player 1 Spawned"));
	}

	PlayerController2Ref = UGameplayStatics::CreatePlayer(GetWorld(), 1, true);
	if (PlayerController2Ref != nullptr)
	{		
		FVector PlayerStartLocation_2 = FindPlayerStart(PlayerControllerRef, "Player2")->GetActorLocation();
		//PlayerChararcter_2 = GetWorld()->SpawnActor<AMyCharacter>(PlayerStartLocation_2, { 0,-90,0 }, para1);
		PlayerChararcter_2 = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 1));
		PlayerChararcter_2->PlayerIndex = 1;
		PlayerChararcter_2->switchImage(2);
		PlayerController2Ref->Possess(UGameplayStatics::GetPlayerCharacter(GetWorld(), 1));
		UE_LOG(LogTemp, Warning, TEXT("Player 2 Spawned"));
	}

	PlayerController3Ref = UGameplayStatics::CreatePlayer(GetWorld(), 2, true);
	if (PlayerController3Ref != nullptr)
	{
		FVector PlayerStartLocation_3 = FindPlayerStart(PlayerControllerRef, "Player3")->GetActorLocation();
		//PlayerChararcter_3 = GetWorld()->SpawnActor<AMyCharacter>(PlayerStartLocation_3, { 0,-90,0 }, para1);
		PlayerChararcter_3 = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 2));
		PlayerChararcter_3->PlayerIndex = 2;
		PlayerChararcter_3->switchImage(3);
		PlayerController3Ref->Possess(UGameplayStatics::GetPlayerCharacter(GetWorld(), 2));
		UE_LOG(LogTemp, Warning, TEXT("Player 3 Spawned"));
	
	}

	PlayerController4Ref = UGameplayStatics::CreatePlayer(GetWorld(), 3, true);
	if (PlayerController4Ref != nullptr)
	{
		FVector PlayerStartLocation_4 = FindPlayerStart(PlayerControllerRef, "Player4")->GetActorLocation();
		//PlayerChararcter_4 = GetWorld()->SpawnActor<AMyCharacter>(PlayerStartLocation_4, { 0,-90,0 }, para1);
		PlayerChararcter_4 = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 3));
		PlayerChararcter_4->PlayerIndex = 3;
		PlayerChararcter_4->switchImage(4);
		PlayerController4Ref->Possess(UGameplayStatics::GetPlayerCharacter(GetWorld(), 3));
		UE_LOG(LogTemp, Warning, TEXT("Player 4 Spawned"));
	
	}

	PlayerChararcter_1->PlayerChararcter_2_ref = PlayerChararcter_2;
	PlayerChararcter_1->PlayerChararcter_3_ref = PlayerChararcter_3;
	PlayerChararcter_1->PlayerChararcter_4_ref = PlayerChararcter_4;


	//Set Camera 
	FViewTargetTransitionParams transitionParams;
	PlayerControllerRef->SetViewTarget(MainCameraRef, transitionParams);

	
	// Create PlayerWdiget
	UW_PlayerUI = CreateWidget<UUserWidget>(PlayerControllerRef, WB_PlayerUI);
	if (UW_PlayerUI)
	{
		UW_PlayerUI->AddToPlayerScreen();
	}
	else {
		UE_LOG(LogTemp, Log, TEXT("Can not find the widget "))
	}
	

}
