// Fill out your copyright notice in the Description page of Project Settings.

#include "Board.h"
#include "ChessField.h"
#include "Engine/World.h"


// Sets default values
ABoard::ABoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	height = 7;
	width = 7;
	ActiveField = nullptr;

}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters Spawnparams;
	Spawnparams.Owner = this;

	F2DPosition tmpPos;
	FTransform tmpTrans(FRotator(0.f, 0.f, 0.f));

	// Spawn chess board
	for (int y = 0; y <= height; y++)
	{
		for (int x = 0; x <= width; x++) {
			
			tmpTrans.SetLocation(FVector(x*100.f, y*-100.f, 0.f));
			tmpPos.x = x;
			tmpPos.y = y;
			
			auto tmp = GetWorld()->SpawnActorDeferred<AChessField>(FieldMesh,tmpTrans, this);
		
			if (y % 2) 
			{
				 tmp->SetFieldParameters(tmpPos, !(x % 2)); // set white or black if it is an uneven row depending on the x value
			}
			else {
				 tmp->SetFieldParameters(tmpPos, true);
			}
			// spawn the field
			UGameplayStatics::FinishSpawningActor(tmp, tmpTrans);

			// add to fields array
			Fields.Add(tmp);
		}

		// Spawn Pieces 
	}

	
}


void ABoard::SpawnAllPieces() 
{
	for (AChessField* Field : Fields)
	{
		// SpawnPawn - black
		if (Field->Position.y == 1) { SpawnFigure(EChessFigure::Chess_Pawn, true, Field->GetActorLocation(), Field->Position); }
		// SpawnPawn - white
		if (Field->Position.x == 6) { SpawnFigure(EChessFigure::Chess_Pawn, false, Field->GetActorLocation(), Field->Position); }


		
		
	}


}

void ABoard::SpawnFigure(EChessFigure FigureType, bool isBlack, FVector SpawnLocation, F2DPosition FigurePosition) 
{


}

// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

