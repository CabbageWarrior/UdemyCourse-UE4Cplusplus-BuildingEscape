// Copyright CabbageWarrior.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(VisibleAnywhere)
		AActor* ActorThatOpens = nullptr;

	UPROPERTY(EditAnywhere)
		float OpenAngle = -90.f;

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 1.f;
	
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;

	float LastDoorOpenTime = 0;
	AActor* Owner = nullptr;

	void OpenDoor();
	void CloseDoor();
};
