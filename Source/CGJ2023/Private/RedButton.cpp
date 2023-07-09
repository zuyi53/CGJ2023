// Fill out your copyright notice in the Description page of Project Settings.


#include "RedButton.h"

// Sets default values
ARedButton::ARedButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> assetRedButton(TEXT("StaticMesh'/Game/Mesh/RedButton.RedButton'"));
	RenButtonImage = CreateDefaultSubobject<UStaticMeshComponent>("RenButtonImage");
	RenButtonImage->SetupAttachment(GetRootComponent());
	RenButtonImage->SetStaticMesh(assetRedButton.Object);
	RenButtonImage->AddRelativeLocation({ 0,0,10 });
	RenButtonImage->SetRelativeRotation({ 0, 90, 0 }, false);

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"));

	if (!ensure(TriggerVolume != nullptr)) return;
	TriggerVolume->SetBoxExtent({ 100, 100, 100 }, true);
	TriggerVolume->AddRelativeLocation({ 0,0 , 86 });
	TriggerVolume->SetupAttachment(RenButtonImage);
	TriggerVolume->SetCollisionResponseToAllChannels(ECR_Overlap);
	//TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ARedButton::OnOverlapBegin);	

	FScriptDelegate DelegateBegin;
	DelegateBegin.BindUFunction(this, "OnOverlapBegin");
	TriggerVolume->OnComponentBeginOverlap.Add(DelegateBegin);


} 
void ARedButton::pressRedButton()
{
	UE_LOG(LogTemp, Log, TEXT("You have press a red button"));

}
void ARedButton::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Activated"));

}
// Called when the game starts or when spawned
void ARedButton::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ARedButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



