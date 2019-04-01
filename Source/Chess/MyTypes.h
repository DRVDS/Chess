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

	F2DPosition() 
		:x(0),y(0)
	{
	}

	F2DPosition(int _x, int _y) 
		:x(_x),y(_y)
	{
	}

};

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class ECF : uint8
{
	Pawn 		UMETA(DisplayName = "Pawn"),
	Horse 		UMETA(DisplayName = "Horse"),
	Bishop 		UMETA(DisplayName = "Bishop"),
	Tower 		UMETA(DisplayName = "Tower"),
	Queen 		UMETA(DisplayName = "Queen"),
	King 		UMETA(DisplayName = "King"),
	Empty		UMETA(DisplayName = "EmptyField")
};





