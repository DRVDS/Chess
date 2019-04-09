// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abstract_Piece.h"
#include "Queen_Piece.generated.h"

/**
 * 
 */
UCLASS()
class CHESS_API AQueen_Piece : public AAbstract_Piece
{
	GENERATED_BODY()
	void GetMoves( TArray<AChessField*>& outValidFields, TArray<AChessField*>& outAttackFields) override
	{
		

		 //horizontal right
		for (int x = FigurePosition.x+1; x < Board->width; x++) 
		{
			AChessField* ret = Board->GetField(F2DPosition(x,FigurePosition.y));
			if (ret && !ret->isOccupied)
			{
				outValidFields.Add(ret);
			}
			else if (ret && !ret->isOccupied && (ret->FigureLocatedOn->isBlack && !this->isBlack) || (!ret->FigureLocatedOn->isBlack && this->isBlack))
			{
				outAttackFields.Add(ret);
				break;
			}
			else {
				break;
			}
		}

		// horizontal left
		for (int x = FigurePosition.x-1; x >= 0; x--) 
		{
			AChessField* ret = Board->GetField(F2DPosition(x, FigurePosition.y));
			if (ret && !ret->isOccupied)
			{
				outValidFields.Add(ret);
			}
			else if (ret && !ret->isOccupied && (ret->FigureLocatedOn->isBlack && !this->isBlack) || (!ret->FigureLocatedOn->isBlack && this->isBlack))
			{
				outAttackFields.Add(ret);
				break;
			}
			else {
				break;
			}
		}

		 //vertical top
		for (int y = FigurePosition.y-1; y >= 0; y--) 
		{
			AChessField* ret = Board->GetField(F2DPosition(FigurePosition.x, y));
			if (ret && !ret->isOccupied)
			{
				outValidFields.Add(ret);
			}
			else if (ret && !ret->isOccupied && (ret->FigureLocatedOn->isBlack && !this->isBlack) || (!ret->FigureLocatedOn->isBlack && this->isBlack))
			{
				outAttackFields.Add(ret);
				break;
			}
			else {
				break;
			}

		}

		// vertical bottom
		for (int y = FigurePosition.y+1; y < Board->height; y++) 
		{
			AChessField* ret = Board->GetField(F2DPosition(FigurePosition.x, y));
			if (ret && !ret->isOccupied)
			{
				outValidFields.Add(ret);
			}
			else if (ret && !ret->isOccupied && (ret->FigureLocatedOn->isBlack && !this->isBlack) || (!ret->FigureLocatedOn->isBlack && this->isBlack))
			{
				outAttackFields.Add(ret);
				break;
			}
			else {
				break;
			}

		}

		 //left up - diagonal
		
		 int x = FigurePosition.x - 1;
		 int y = FigurePosition.y - 1;

		 for (; x >= 0 && y >= 0; x--, y--)
		 {
			 AChessField* ret = Board->GetField(F2DPosition(x, y));
			 if (ret && !ret->isOccupied)
			 {
				 outValidFields.Add(ret);
			 }
			 else if (ret && !ret->isOccupied && (ret->FigureLocatedOn->isBlack && !this->isBlack) || (!ret->FigureLocatedOn->isBlack && this->isBlack))
			 {
				 outAttackFields.Add(ret);
				 break;
			 }
			 else {
				 break;
			 }
		 }
		 //right down - diagonal

		 x = FigurePosition.x+1; 
		 y = FigurePosition.y+1;

		for (; x < Board->width && y <Board->height; x++, y++) 
		{
			AChessField* ret = Board->GetField(F2DPosition(x, y));
			if (ret && !ret->isOccupied)
			{
				outValidFields.Add(ret);
			}
			else if (ret && !ret->isOccupied && (ret->FigureLocatedOn->isBlack && !this->isBlack) || (!ret->FigureLocatedOn->isBlack && this->isBlack))
			{
				outAttackFields.Add(ret);
				break;
			}
			else {
				break;
			}
		}
		 //left down - diagonal
		
		x = FigurePosition.x-1;
		y = FigurePosition.y+1;
		
		for (; x >= 0 && y < Board->height; x--, y++) 
		{
			AChessField* ret = Board->GetField(F2DPosition(x, y));
			if (ret && !ret->isOccupied)
			{
				outValidFields.Add(ret);
			}
			else if (ret && !ret->isOccupied && (ret->FigureLocatedOn->isBlack && !this->isBlack) || (!ret->FigureLocatedOn->isBlack && this->isBlack))
			{
				outAttackFields.Add(ret);
				break;
			}
			else {
				break;
			}
		}
		// right up - diagonal

		x = FigurePosition.x+1;
		y = FigurePosition.y-1;

		for (; x < Board->width && y >= 0; x++, y--) 
		{
			AChessField* ret = Board->GetField(F2DPosition(x, y));
			if (ret && !ret->isOccupied)
			{
				outValidFields.Add(ret);
			}
			else if (ret && !ret->isOccupied && (ret->FigureLocatedOn->isBlack && !this->isBlack) || (!ret->FigureLocatedOn->isBlack && this->isBlack))
			{
				outAttackFields.Add(ret);
				break;
			}
			else {
				break;
			}
		}


		UE_LOG(LogTemp, Warning, TEXT("Hello from Queen! %i  fields - I could attack"), outValidFields.Num());

	}
	
};
