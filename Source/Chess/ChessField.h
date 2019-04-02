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

	UFUNCTION(BlueprintCallable)
	void SetFieldParameters(F2DPosition Position, bool isWhite);

	UFUNCTION(BlueprintCallable)
	void SpawnFigure(TSubclassOf<AAbstract_Piece> PieceToSpawn, bool isBlack);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	F2DPosition Position;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool isOccupied;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ABoard* Board;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool isWhite;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* FieldMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USceneComponent* CenterOfBoard;

	UPROPERTY()
		UMaterialInstanceConstant* Black;
	UPROPERTY()
		UMaterialInstanceConstant* White;

	// Delegates for MouseCursor Overlap
	UFUNCTION()
		void FieldOnBeginCursorOver(UPrimitiveComponent* Component);

	UFUNCTION()
		void FieldOnEndCursorOver(UPrimitiveComponent* Component);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
