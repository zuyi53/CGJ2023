// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacter.h"
#include "item.h"
#include "RedButton.h"
#include "GameFramework/GameModeBase.h"
#include "CGJ2023GameModeBase.generated.h"
/** * 
 */
UCLASS()
class CGJ2023_API ACGJ2023GameModeBase : public AGameModeBase
{
	GENERATED_BODY()


public:
	ACGJ2023GameModeBase();
	~ACGJ2023GameModeBase();

public:

	virtual void Tick(float DeltaTime) override;



	UPROPERTY(BlueprintReadWrite, Category = "CGJ2023")
		ACameraActor* MainCameraRef;

	TSubclassOf<ACameraActor> CameraActorClass;
	TArray<AActor*> MainCameraList;

	ACameraActor* MainCamera;
	virtual void StartPlay() override;

	TSubclassOf<UUserWidget> WB_PlayerUI;
	UUserWidget *UW_PlayerUI;


	UPROPERTY(BlueprintReadWrite, Category = "CGJ2023")
		APlayerController* PlayerControllerRef;

	UPROPERTY(BlueprintReadWrite, Category = "CGJ2023")
		APlayerController* PlayerController2Ref;

	UPROPERTY(BlueprintReadWrite, Category = "CGJ2023")
		APlayerController* PlayerController3Ref;

	UPROPERTY(BlueprintReadWrite, Category = "CGJ2023")
		APlayerController* PlayerController4Ref;
	
	TArray<ARedButton*> RedButton_List;
	TArray<Aitem*> ItemL_ist;

	AMyCharacter* PlayerChararcter_1;
	AMyCharacter* PlayerChararcter_2;
	AMyCharacter* PlayerChararcter_3;
	AMyCharacter* PlayerChararcter_4;

	UPROPERTY(BlueprintReadWrite, Category = "CGJ2023")
	float MaxTime = 120.f;


	void GetAllRedButtonLocation();
	
};
