#include "CurveMovement.h"

UCurveMovement::UCurveMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void UCurveMovement::BeginPlay()
{
	Super::BeginPlay();

	ElapsedTime = 0;
	float min, max;
	VectorCurve->GetTimeRange(min, max);
	CurveMaxTime = max;
}

void UCurveMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	ElapsedTime += DeltaTime * Speed;
	if (ElapsedTime > CurveMaxTime) {
		ElapsedTime -= CurveMaxTime;
	}

	FVector currentVectorValue = VectorCurve->GetVectorValue(ElapsedTime)
	AActor* actor = GetOwner();
	actor->SetActorLocation(currentVectorValue, false);
}