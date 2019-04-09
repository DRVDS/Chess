// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyTypes.h"
#include "Board.h"
#include "ChessField.h"
#include "Abstract_Piece.generated.h"



UCLASS()
class CHESS_API AAbstract_Piece : public AActor 
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

	UPROPERTY(VisibleAnywhere)
	bool hasMoved;

	UPROPERTY(VisibleAnywhere)
	ABoard* Board;

	UFUNCTION()
	void ActivatePiece();

	UFUNCTION()
	void DeactivatePiece();

	// gets all the free fields the figure can move to
	UFUNCTION()
	virtual void GetMoves( TArray<AChessField*>& outValidFields, TArray<AChessField*>& outAttackFields);

	UFUNCTION()
	virtual void MoveTo(F2DPosition Goal);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};
