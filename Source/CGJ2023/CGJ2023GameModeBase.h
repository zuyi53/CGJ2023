// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MulitPlayerManager.h"
#include "GameFramework/GameModeBase.h"
#include "CGJ2023GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CGJ2023_API ACGJ2023GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public: 
public:
	ACGJ2023GameModeBase();
	~ACGJ2023GameModeBase();

public:


	UPROPERTY(BlueprintReadWrite, Category = "CGJ2023")
		ACameraActor* MainCameraRef;

	TSubclassOf<ACameraActor> CameraActorClass;
	TArray<AActor*> MainCameraList;

	ACameraActor* MainCamera;
	virtual void StartPlay() override;

	AMulitPlayerManager* MulitPlayerManagerRef;




	UPROPERTY(BlueprintReadWrite, Category = "CGJ2023")
		APlayerController* PlayerControllerRef;

	UPROPERTY(BlueprintReadWrite, Category = "CGJ2023")
		APlayerController* PlayerController2Ref;

	UPROPERTY(BlueprintReadWrite, Category = "CGJ2023")
		APlayerController* PlayerController3Ref;

	UPROPERTY(BlueprintReadWrite, Category = "CGJ2023")
		APlayerController* PlayerController4Ref;

	AMyCharacter* PlayerChararcter_1;
	AMyCharacter* PlayerChararcter_2;
	AMyCharacter* PlayerChararcter_3;
	AMyCharacter* PlayerChararcter_4;
	
};
