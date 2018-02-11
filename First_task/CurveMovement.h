// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Curves/CurveVector.h"
#include "CurveMovement.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class AIVPROJECT_API UCurveMovement : public USceneComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		UCurveVector* VectorCurve;
	UPROPERTY(EditAnywhere)
		float Speed;

	UCurveMovement();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:
	float ElapsedTime;
	float CurveMaxTime;
};