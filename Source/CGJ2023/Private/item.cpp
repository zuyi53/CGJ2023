// Fill out your copyright notice in the Description page of Project Settings.


#include "item.h"

// Sets default values
Aitem::Aitem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> assetRedButton(TEXT("StaticMesh'/Game/Mesh/Item.Item'"));
	ItemImage = CreateDefaultSubobject<UStaticMeshComponent>("ItemImage");
	ItemImage->SetupAttachment(GetRootComponent());
	ItemImage->SetStaticMesh(assetRedButton.Object);
	ItemImage->SetRelativeRotation({ 0, 90, 0 }, false);
}

// Called when the game starts or when spawned
void Aitem::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void Aitem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

