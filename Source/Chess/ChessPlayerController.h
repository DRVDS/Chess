// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ChessPlayerController.generated.h"


class ABoard;

/**
 * 
 */
UCLASS()
class CHESS_API AChessPlayerController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY()
	ABoard* MyBoard;

	UFUNCTION()
	void BeginPlay();

public:
	UPROPERTY()
	float MouseYawSensitivity = 300.f;
	UPROPERTY()
	float MousePitchSensitivity = 10.f;
	UPROPERTY()
	float ZoomSensitity = 100.f;


};
