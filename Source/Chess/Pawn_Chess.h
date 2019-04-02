// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abstract_Piece.h"
#include "Pawn_Chess.generated.h"

/**
 * 
 */
UCLASS()
class CHESS_API APawn_Chess : public AAbstract_Piece
{
	GENERATED_BODY()
		void GetValidMoves(AChessField* outValidFields) override {};
};
