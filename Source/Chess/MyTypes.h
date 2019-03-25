// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine.h"
#include "CoreMinimal.h"
#include "MyTypes.generated.h"   // have to edit this in manually in order to be able to use the struct


USTRUCT(BlueprintType)
struct F2DPosition
{
	GENERATED_BODY()

		UPROPERTY(BlueprintReadWrite)
		int32 x;

	UPROPERTY(BlueprintReadWrite)
		int32 y;

};

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EChessFigure : uint8
{
	Chess_Pawn 		UMETA(DisplayName = "Pawn"),
	Chess_Horse 	UMETA(DisplayName = "Horse"),
	Chess_Bishop 	UMETA(DisplayName = "Bishop"),
	Chess_Tower 	UMETA(DisplayName = "Tower"),
	Chess_Queen 	UMETA(DisplayName = "Queen"),
	Chess_King 		UMETA(DisplayName = "King")
};



