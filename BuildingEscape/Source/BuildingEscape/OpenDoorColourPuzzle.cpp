// Copyright Ben Rowe 2018

#include "OpenDoorColourPuzzle.h"
#include "Containers/Array.h"

#define OUT
// Sets default values for this component's properties
UOpenDoorColourPuzzle::UOpenDoorColourPuzzle()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoorColourPuzzle::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();

	if (!GreenTrigger || !RedTrigger || !PurpleTrigger)
	{
		UE_LOG(LogTemp, Error, TEXT("One or more trigger not set on %s"), *Owner->GetName());
		return;
	}

	if (!GreenKey || !RedKey || !PurpleKey)
	{
		UE_LOG(LogTemp, Error, TEXT("One or more key not set on %s"), *Owner->GetName());
		return;
	}
	// ...
	
}


// Called every frame
void UOpenDoorColourPuzzle::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsAllColoursOnPlates())	
	{
		OnOpen.Broadcast();
	}
	else
	{
		OnClose.Broadcast();
	}

}

bool UOpenDoorColourPuzzle::IsAllColoursOnPlates()
{
	int CorrectKeyCount = 0;

	TArray<AActor*> OverlappingActorsGreen;
	TArray<AActor*> OverlappingActorsRed;
	TArray<AActor*> OverlappingActorsPurple;

	PurpleTrigger->GetOverlappingActors(OUT OverlappingActorsPurple);
	RedTrigger->GetOverlappingActors(OUT OverlappingActorsRed);
	GreenTrigger->GetOverlappingActors(OUT OverlappingActorsGreen);

	for(const auto* Actor : OverlappingActorsPurple)
	{
		if (Actor->ActorHasTag("PurpleKey"))
		{
			UE_LOG(LogTemp, Warning, TEXT("Purple Key Entered volume"))
				CorrectKeyCount++;
		}
	};
	//if (!GreenTrigger ->IsOverlappingActor(GreenKey))
	//{
	//	return false;
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Green Key Entered Green volume"))
	//}

	//if (!RedTrigger->IsOverlappingActor(RedKey))
	//{
	//	return false;
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Red Key Entered Green volume"))
	//}

	//if (!PurpleTrigger ->IsOverlappingActor(PurpleKey))
	//{
	//	return false;
	//}

	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Purple key Entered Green volume"))
	//}

	return false;
}

