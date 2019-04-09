// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTypes.h"
#include "Board.generated.h"

class AChessField;
class AAbstract_Piece;
class UCameraComponent;
class USpringArmComponent;
class AChessPlayerController;

UCLASS()
class CHESS_API ABoard : public APawn
{
	GENERATED_BODY()
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Sets default values for this actor's properties
	ABoard();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCameraComponent* GameCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USceneComponent* SpringArmAncor;


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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AAbstract_Piece* ActivePiece = nullptr;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	AChessField* GetField(F2DPosition Coordinates);

	UPROPERTY()
	FVector	GoalLocMovePieceTo;


	// Get All of the Mouse stuff to the Player Controller

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AChessPlayerController* PC;

	// Mouse Functions
	UFUNCTION()
	void MouseYaw(float axis);
	UFUNCTION()
	void MousePitch(float axis);
	UFUNCTION()
	void Zoom(float axis);
	UFUNCTION()
	void LeftMouseClicked();

};
