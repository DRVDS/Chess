// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTypes.h"
#include "Board.generated.h"

class AChessField;

UCLASS()
class CHESS_API ABoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Sets default values for this actor's properties
	ABoard();

	UFUNCTION(BlueprintCallable)
	void SpawnAllPieces();

	UFUNCTION(BlueprintCallable)
	void SpawnFigure(EChessFigure FigureType, bool isBlack, FVector SpawnLocation, F2DPosition FigurePosition);


	UPROPERTY(BlueprintReadWrite)
		int height;

	UPROPERTY(BlueprintReadWrite)
		int width;

	UPROPERTY(BlueprintReadWrite)
		TArray<AChessField*> Fields;

	UPROPERTY(BlueprintReadWrite)
		AChessField* ActiveField;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AChessField> FieldMesh;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};
