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

	UFUNCTION()
	void SetupInputComponent() override;

	UFUNCTION()
	void MouseYaw(float axis);
	UFUNCTION()
	void MousePitch(float axis);
	//UFUNCTION()
	//void SetZoom( float axis);

};
