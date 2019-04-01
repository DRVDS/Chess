// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyTypes.h"
#include "Abstract_Piece.generated.h"

UCLASS()
class CHESS_API AAbstract_Piece : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAbstract_Piece();
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* FigureStaticMesh;

	UPROPERTY(VisibleAnywhere)
	bool isBlack;

	UPROPERTY(VisibleAnywhere)
	ECF FigureType;

	UPROPERTY(VisibleAnywhere)
	F2DPosition FigurePosition;

	UFUNCTION()
	void ActivatePiece();

	UFUNCTION()
	void DeactivatePiece();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
