// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abstract_Piece.h"
#include "Horse_Piece.generated.h"

/**
 * 
 */
UCLASS()
class CHESS_API AHorse_Piece : public AAbstract_Piece
{
	GENERATED_BODY()

		void GetMoves(TArray<AChessField*>& outValidFields, TArray<AChessField*>& outAttackFields) override
	{
		AChessField* ret = Board->GetField(F2DPosition(FigurePosition.x + 1, FigurePosition.y + 2));
		if (ret && !ret->isOccupied)
		{
			outValidFields.Add(ret);
		}
		else if (ret && !ret->isOccupied && (ret->FigureLocatedOn->isBlack && !this->isBlack) || (!ret->FigureLocatedOn->isBlack && this->isBlack))
		{
			outAttackFields.Add(ret);
		}
			
		ret = Board->GetField(F2DPosition(FigurePosition.x - 1, FigurePosition.y + 2));
		if (ret && !ret->isOccupied)
		{
			outValidFields.Add(ret);
		}
		else if (ret && !ret->isOccupied && (ret->FigureLocatedOn->isBlack && !this->isBlack) || (!ret->FigureLocatedOn->isBlack && this->isBlack))
		{
			outAttackFields.Add(ret);
		}

		ret = Board->GetField(F2DPosition(FigurePosition.x + 1, FigurePosition.y - 2));
		if (ret && !ret->isOccupied)
		{
			outValidFields.Add(ret);
		}
		else if (ret && !ret->isOccupied && (ret->FigureLocatedOn->isBlack && !this->isBlack) || (!ret->FigureLocatedOn->isBlack && this->isBlack))
		{
			outAttackFields.Add(ret);
		}

		ret = Board->GetField(F2DPosition(FigurePosition.x - 1, FigurePosition.y - 2));
			if (ret && !ret->isOccupied)
			{
				outValidFields.Add(ret);
			}
			else if (ret && !ret->isOccupied && (ret->FigureLocatedOn->isBlack && !this->isBlack) || (!ret->FigureLocatedOn->isBlack && this->isBlack))
			{
				outAttackFields.Add(ret);
			}

		ret = Board->GetField(F2DPosition(FigurePosition.x - 1, FigurePosition.y + 2));
			if (ret && !ret->isOccupied)
			{
				outValidFields.Add(ret);
			}
			else if (ret && !ret->isOccupied && (ret->FigureLocatedOn->isBlack && !this->isBlack) || (!ret->FigureLocatedOn->isBlack && this->isBlack))
			{
				outAttackFields.Add(ret);
			}

		ret = Board->GetField(F2DPosition(FigurePosition.x - 2, FigurePosition.y - 1));
			if (ret && !ret->isOccupied)
			{
				outValidFields.Add(ret);
			}
			else if (ret && !ret->isOccupied && (ret->FigureLocatedOn->isBlack && !this->isBlack) || (!ret->FigureLocatedOn->isBlack && this->isBlack))
			{
				outAttackFields.Add(ret);
			}

		ret = Board->GetField(F2DPosition(FigurePosition.x + 2, FigurePosition.y + 1));
			if (ret && !ret->isOccupied)
			{
				outValidFields.Add(ret);
			}
			else if (ret && !ret->isOccupied && (ret->FigureLocatedOn->isBlack && !this->isBlack) || (!ret->FigureLocatedOn->isBlack && this->isBlack))
			{
				outAttackFields.Add(ret);
			}

		ret = Board->GetField(F2DPosition(FigurePosition.x - 2, FigurePosition.y + 1));
			if (ret && !ret->isOccupied)
			{
				outValidFields.Add(ret);
			}
			else if (ret && !ret->isOccupied && (ret->FigureLocatedOn->isBlack && !this->isBlack) || (!ret->FigureLocatedOn->isBlack && this->isBlack))
			{
				outAttackFields.Add(ret);
			}
		

			 UE_LOG(LogTemp, Warning, TEXT("Hello from Horse"));
		 };
	
};
