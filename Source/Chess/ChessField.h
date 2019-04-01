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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	F2DPosition Position;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ABoard* Board;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isWhite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* FieldMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* CenterOfBoard;

	UPROPERTY()
		UMaterialInstanceConstant* Black;
	UPROPERTY()
		UMaterialInstanceConstant* White;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
