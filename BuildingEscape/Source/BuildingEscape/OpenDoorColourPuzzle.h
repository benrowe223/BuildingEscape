// Copyright Ben Rowe 2018

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoorColourPuzzle.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FColourDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoorColourPuzzle : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoorColourPuzzle();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(BlueprintAssignable)
		FColourDoorEvent OnOpen;
	UPROPERTY(BlueprintAssignable)
		FColourDoorEvent OnClose;

private:

	UPROPERTY(EditAnywhere)
	ATriggerVolume* GreenTrigger = nullptr;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* RedTrigger = nullptr;

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PurpleTrigger = nullptr;

	UPROPERTY(EditAnywhere)
	AActor* PurpleKey = nullptr;

	UPROPERTY(EditAnywhere)
	AActor* RedKey = nullptr;

	UPROPERTY(EditAnywhere)
	AActor* GreenKey = nullptr;

	AActor* Owner;

	bool IsAllColoursOnPlates();
};
