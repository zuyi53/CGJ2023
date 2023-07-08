// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class CGJ2023_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(VisibleAnywhere , Category= "CGJ2023")
	UStaticMeshComponent *CharacterImage;

	UCapsuleComponent* Capsule;

	void switchImage(int32 index);

	UPROPERTY(VisibleAnywhere, Category = "CGJ2023")
	int32 PlayerIndex = 0;

	void Player1_Interactive();
	void Player1_Skill();
	void Player2_Interactive();
	void Player2_Skill();
	void Player3_Interactive();
	void Player3_Skill();
	void Player4_Interactive();
	void Player4_Skill();

	void Player1_MoveUp(float axisValue);
	void Player1_MoveRight(float axisValue);
	void Player2_MoveUp(float axisValue);
	void Player2_MoveRight(float axisValue);
	void Player3_MoveUp(float axisValue);
	void Player3_MoveRight(float axisValue);
	void Player4_MoveUp(float axisValue);
	void Player4_MoveRight(float axisValue);

	

	UPROPERTY(VisibleAnywhere, Category = "CGJ2023")
	float speed = 10.f;

	UPROPERTY(VisibleAnywhere, Category = "CGJ2023")
	UStaticMesh* SM_Player1;
	UPROPERTY(VisibleAnywhere, Category = "CGJ2023")
	UStaticMesh* SM_Player2;
	UPROPERTY(VisibleAnywhere, Category = "CGJ2023")
	UStaticMesh* SM_Player3;
	UPROPERTY(VisibleAnywhere, Category = "CGJ2023")
	UStaticMesh* SM_Player4;
	UPROPERTY(VisibleAnywhere, Category = "CGJ2023")
	AMyCharacter* PlayerChararcter_1 = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "CGJ2023")
	AMyCharacter* PlayerChararcter_2_ref = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "CGJ2023")
	AMyCharacter* PlayerChararcter_3_ref = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "CGJ2023")
	AMyCharacter* PlayerChararcter_4_ref = nullptr;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool bEnablePickup = false;

};
