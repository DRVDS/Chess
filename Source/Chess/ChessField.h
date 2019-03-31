// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTypes.h"
#include "ChessField.generated.h"

class ABoard;

UCLASS()
class CHESS_API AChessField : public AActor
{
	GENERATED_BODY()
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Sets default values for this actor's properties
	AChessField();

	UFUNCTION(BlueprintCallable)
	void SetFieldParameters(F2DPosition Position, bool isWhite);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	F2DPosition Position;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ABoard* Board;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isWhite;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
