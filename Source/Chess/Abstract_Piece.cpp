// Fill out your copyright notice in the Description page of Project Settings.

#include "Abstract_Piece.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AAbstract_Piece::AAbstract_Piece()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	FigureStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FigureMesh"));
	FigureStaticMesh->SetupAttachment(RootComponent);
	



}

// Called when the game starts or when spawned
void AAbstract_Piece::BeginPlay()
{
	Super::BeginPlay();

	Board = Cast<ABoard>(GetOwner());
	hasMoved = false;
}

void AAbstract_Piece::ActivatePiece()
{

}

void AAbstract_Piece::DeactivatePiece()
{

}

void AAbstract_Piece::GetMoves( TArray<AChessField*>& outValidFields, TArray<AChessField*>& outAttackFields)
{
	UE_LOG(LogTemp, Warning, TEXT("Hello from parent"));
}


void AAbstract_Piece::MoveTo(F2DPosition Goal) 
{
	AChessField* goalField = Board->GetField(Goal);
	if (goalField)
	{
		Board->GoalLocMovePieceTo = goalField->CenterOfBoard->GetComponentLocation();
		
		hasMoved = true;
	}
	
}
