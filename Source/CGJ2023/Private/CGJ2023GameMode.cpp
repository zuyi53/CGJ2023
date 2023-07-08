// Copyright Epic Games, Inc. All Rights Reserved.

#include "CGJ2023GameMode.h"
#include "CGJ2023Character.h"
#include "UObject/ConstructorHelpers.h"

ACGJ2023GameMode::ACGJ2023GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
