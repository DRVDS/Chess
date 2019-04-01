// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTypes.h"
#include "Board.generated.h"

class AChessField;
class AAbstract_Piece;

UCLASS()
class CHESS_API ABoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Sets default values for this actor's properties
	ABoard();


	UPROPERTY(BlueprintReadWrite)
	int height;

	UPROPERTY(BlueprintReadWrite)
	int width;

	// holds references to all the Fields
	UPROPERTY(BlueprintReadWrite)
	TArray<AChessField*> Fields;

	UPROPERTY(BlueprintReadWrite)
	AChessField* ActiveField;

	// determines what figure should be spawned on this field index if any
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<ECF> FigureAtPosition;

	// what type of field should be spawned ?
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AChessField> FieldActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<ECF, TSubclassOf<AAbstract_Piece>> Pieces;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};
