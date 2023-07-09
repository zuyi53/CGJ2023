// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "MyGameViewportClient.generated.h"

/**
 * 
 */
UCLASS()
class CGJ2023_API UMyGameViewportClient : public UGameViewportClient
{
	GENERATED_BODY()

public:

	virtual void UpdateActiveSplitscreenType() override;
};
