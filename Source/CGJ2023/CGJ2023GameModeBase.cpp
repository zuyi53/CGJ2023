// Copyright Epic Games, Inc. All Rights Reserved.


#include "CGJ2023GameModeBase.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"



ACGJ2023GameModeBase::ACGJ2023GameModeBase()
{
	DefaultPawnClass = AMyCharacter::StaticClass();

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


	PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerControllerRef)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player1 Spawned"));
		PlayerChararcter_1 = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		PlayerChararcter_1->PlayerIndex = 0;
		PlayerControllerRef->Possess(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));	
		UE_LOG(LogTemp, Warning, TEXT("Player1 bind to Character "));
	}

	PlayerController2Ref = UGameplayStatics::CreatePlayer(GetWorld(), 1, true);
	if (PlayerController2Ref != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player2 Spawned"));
		PlayerChararcter_2 = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 1));
		PlayerChararcter_2->PlayerIndex = 1;
		PlayerController2Ref->Possess(UGameplayStatics::GetPlayerCharacter(GetWorld(), 1));
		UE_LOG(LogTemp, Warning, TEXT("Player2 bind to Character "));

	}

	PlayerController3Ref = UGameplayStatics::CreatePlayer(GetWorld(), 2, true);
	if (PlayerController3Ref != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player3 Spawned"));
		PlayerChararcter_3 = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 2));
		PlayerChararcter_3->PlayerIndex = 2;
		PlayerController3Ref->Possess(UGameplayStatics::GetPlayerCharacter(GetWorld(), 2));
		UE_LOG(LogTemp, Warning, TEXT("Player3 bind to Character "));
	
	}

	PlayerController4Ref = UGameplayStatics::CreatePlayer(GetWorld(), 3, true);
	if (PlayerController4Ref != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player4 Spawned"));
		PlayerChararcter_4 = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 3));
		PlayerChararcter_4->PlayerIndex = 3;
		PlayerController4Ref->Possess(UGameplayStatics::GetPlayerCharacter(GetWorld(), 3));
		UE_LOG(LogTemp, Warning, TEXT("Player4 bind to Character "));
	
	}

	PlayerChararcter_1->PlayerChararcter_2_ref = PlayerChararcter_2;
	PlayerChararcter_1->PlayerChararcter_3_ref = PlayerChararcter_3;
	PlayerChararcter_1->PlayerChararcter_4_ref = PlayerChararcter_4;


	//Set Camera 
	FViewTargetTransitionParams transitionParams;
	PlayerControllerRef->SetViewTarget(MainCameraRef, transitionParams);
}
