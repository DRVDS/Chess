// Fill out your copyright notice in the Description page of Project Settings.

#include "Pawn_Chess.h"


void APawn_Chess::GetMoves( TArray<AChessField*>& outValidFields, TArray<AChessField*>& outAttackFields)
{
	int YindexToTest;	
	// the field index we have to check depends on the colour of the pawn
	isBlack ? YindexToTest = FigurePosition.y - 1 : YindexToTest = FigurePosition.y + 1;

	AChessField* ret = Board->GetField(F2DPosition(FigurePosition.x, YindexToTest));
	if (ret && !ret->isOccupied)
	{
		outValidFields.Add(ret);

		// check if Pawn is in starting position and the field in front of him is unoccupied
		if (!hasMoved)
		{
			isBlack ? YindexToTest = FigurePosition.y - 2 : YindexToTest = FigurePosition.y + 2;
			ret = Board->GetField(F2DPosition(FigurePosition.x, YindexToTest));

			if (!ret->isOccupied)
			{
				outValidFields.Add(ret);
			}
		}
	}
	// check for attack vectors
	if (isBlack)	// if we are black
	{
		AChessField* ret = Board->GetField(F2DPosition(FigurePosition.x + 1, FigurePosition.y - 1));
		if (ret && ret->isOccupied && !ret->FigureLocatedOn->isBlack)  // check if the other field is occupied by white
		{
			outAttackFields.Add(ret);
		}
		ret = Board->GetField(F2DPosition(FigurePosition.x - 1, FigurePosition.y - 1));
		if (ret && ret->isOccupied && !ret->FigureLocatedOn->isBlack)
		{
			outAttackFields.Add(ret);
		}
	}
	else {		// if we are white 
		AChessField* ret = Board->GetField(F2DPosition(FigurePosition.x + 1, FigurePosition.y + 1));
		if (ret && ret->isOccupied && ret->FigureLocatedOn->isBlack) // check if the other field is occupied by black
		{
			outAttackFields.Add(ret);
		}
		ret = Board->GetField(F2DPosition(FigurePosition.x - 1, FigurePosition.y + 1));
		if (ret && ret->isOccupied && ret->FigureLocatedOn->isBlack)
		{
			outAttackFields.Add(ret);
		}
	}
}



