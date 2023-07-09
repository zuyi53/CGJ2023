// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "RedButton.generated.h"



UCLASS()
class CGJ2023_API ARedButton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARedButton();

	UPROPERTY(VisibleAnywhere, Category = "CGJ2023")
	UStaticMeshComponent* RenButtonImage;

	UPROPERTY(VisibleAnywhere, Category = "CGJ2023")
	UBoxComponent* TriggerVolume;

	UFUNCTION(BLueprintCallable, Category = "CGJ2023")
		void pressRedButton();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
