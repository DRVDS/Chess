// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abstract_Piece.h"
#include "Bishop_Chess.generated.h"



/**
 * 
 */
UCLASS()
class CHESS_API ABishop_Chess : public AAbstract_Piece
{
	GENERATED_BODY()

		 void GetMoves( TArray<AChessField*>& outValidFields, TArray<AChessField*>& outAttackFields) override {

		//left up - diagonal

		int x = FigurePosition.x - 1;
		int y = FigurePosition.y - 1;

		for (; x >= 0 && y >= 0; x--, y--)
		{
			AChessField* ret = Board->GetField(F2DPosition(x, y));
			if (ret && !ret->isOccupied)
			{
				outValidFields.Add(ret);	// this is a movable field
			}
			else if (ret && !ret->isOccupied &&
				(ret->FigureLocatedOn->isBlack && !this->isBlack) ||		// check if there is an enemy on the field
				(!ret->FigureLocatedOn->isBlack && this->isBlack))
			{
				outAttackFields.Add(ret);
				break;	// break on first enemy 
			}
			else {
				break; // break if we reach the edge of the board
			}
		}

		//right down - diagonal

		x = FigurePosition.x + 1;
		y = FigurePosition.y + 1;

		for (; x < Board->width && y < Board->height; x++, y++)
		{
			AChessField* ret = Board->GetField(F2DPosition(x, y));
			if (ret && !ret->isOccupied)
			{
				outValidFields.Add(ret);	// this is a movable field
			}
			else if (ret && !ret->isOccupied &&
				(ret->FigureLocatedOn->isBlack && !this->isBlack) ||		// check if there is an enemy on the field
				(!ret->FigureLocatedOn->isBlack && this->isBlack))
			{
				outAttackFields.Add(ret);
				break;	// break on first enemy 
			}
			else {
				break; // break if we reach the edge of the board
			}
		}
		//left down - diagonal

		x = FigurePosition.x - 1;
		y = FigurePosition.y + 1;

		for (; x >= 0 && y < Board->height; x--, y++)
		{
			AChessField* ret = Board->GetField(F2DPosition(x, y));
			if (ret && !ret->isOccupied)
			{
				outValidFields.Add(ret);	// this is a movable field
			}
			else if (ret && !ret->isOccupied &&
				(ret->FigureLocatedOn->isBlack && !this->isBlack) ||		// check if there is an enemy on the field
				(!ret->FigureLocatedOn->isBlack && this->isBlack))
			{
				outAttackFields.Add(ret);
				break;	// break on first enemy 
			}
			else {
				break; // break if we reach the edge of the board
			}
		}
		// right up - diagonal

		x = FigurePosition.x + 1;
		y = FigurePosition.y - 1;

		for (; x < Board->width && y >= 0; x++, y--)
		{
			AChessField* ret = Board->GetField(F2DPosition(x, y));
			if (ret && !ret->isOccupied)
			{
				outValidFields.Add(ret);	// this is a movable field
			}
			else if (ret && !ret->isOccupied &&
				(ret->FigureLocatedOn->isBlack && !this->isBlack) ||		// check if there is an enemy on the field
				(!ret->FigureLocatedOn->isBlack && this->isBlack))
			{
				outAttackFields.Add(ret);
				break;	// break on first enemy 
			}
			else {
				break; // break if we reach the edge of the board
			}
		}


		UE_LOG(LogTemp, Warning, TEXT("Hello from Bishop  %i  fields - I could attack"), outValidFields.Num());
	};
	
};
