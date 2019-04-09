// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTypes.h"

#include "ChessField.generated.h"

class ABoard;
class UStaticMeshComponent;
class AAbstract_Piece;

UCLASS()
class CHESS_API AChessField : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChessField();

	// helper functions to set the x and y position and colour during spawning
	UFUNCTION(BlueprintCallable)
	void SetFieldParameters(F2DPosition Position, bool isWhite);

	// function to help spawn figure at the location at Position  
	UFUNCTION(BlueprintCallable)
	void SpawnFigure(TSubclassOf<AAbstract_Piece> PieceToSpawn, bool isBlack, ECF FigureType);
	
	// position vector of field
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	F2DPosition Position;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool isOccupied;

	// holds a reference to the board
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ABoard* Board;

	// holds a reference to the figure that was spawned on it
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AAbstract_Piece* FigureLocatedOn;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool isWhite;
	
	// components and materials needed for the field
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* FieldMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USceneComponent* CenterOfBoard;
	UPROPERTY()
	UMaterialInstanceConstant* Black;
	UPROPERTY()
	UMaterialInstanceConstant* White;
	UPROPERTY()
	UMaterialInstanceConstant* DebugColor;
	UPROPERTY()
	UMaterialInstanceConstant* AttackColor;
	
	// Delegates for MouseCursor Overlap
	UFUNCTION()
		void FieldOnBeginCursorOver(UPrimitiveComponent* Component);

	UFUNCTION()
		void FieldOnEndCursorOver(UPrimitiveComponent* Component);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
