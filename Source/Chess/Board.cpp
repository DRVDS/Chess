// Fill out your copyright notice in the Description page of Project Settings.

#include "Board.h"
#include "MyTypes.h"
#include "ChessField.h"
#include "Engine/World.h"
#include "Abstract_Piece.h"

#include "Horse_Piece.h"
#include "Queen_Piece.h"
#include "King_Piece.h"


// Sets default values
ABoard::ABoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	height = 7;
	width = 7;
	ActiveField = nullptr;

	FigureAtPosition = { ECF::Tower, ECF::Horse, ECF::Bishop, ECF::Queen, ECF::King, ECF::Bishop,ECF::Horse, ECF::Tower,
						 ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn,
						ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,
						ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,
						ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,
						ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,
						ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn,
						ECF::Tower, ECF::Horse, ECF::Bishop, ECF::Queen, ECF::King, ECF::Bishop,ECF::Horse, ECF::Tower };


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
			
			tmpTrans.SetLocation(FVector(x*400.f, y*-400.f, 0.f));
			tmpPos.x = x;
			tmpPos.y = y;
			
			auto tmp = GetWorld()->SpawnActorDeferred<AChessField>(FieldActor,tmpTrans, this);
		
			if (y % 2) 
			{
				 tmp->SetFieldParameters(tmpPos, (x % 2)); // set white or black if it is an uneven row depending on the x value
			}
			else {
				 tmp->SetFieldParameters(tmpPos, !(x % 2));
			}
			// spawn the field
			UGameplayStatics::FinishSpawningActor(tmp, tmpTrans);

			// Check what figure should be spawned and what colour
			
			auto FigureType = FigureAtPosition[x + y * width];
			
			if(FigureType != ECF::Empty)
			{
				auto ClassToSpawn = Pieces.FindRef(FigureType);
				tmp->SpawnFigure(ClassToSpawn, x + y * width < 20 ? true : false);
			}
			
		

			// add to fields array
			Fields.Add(tmp);

		}

	}

	
}



// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

