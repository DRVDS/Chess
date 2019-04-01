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
	
}

void AAbstract_Piece::ActivatePiece()
{

}

void AAbstract_Piece::DeactivatePiece()
{

}


// Called to bind functionality to input
void AAbstract_Piece::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

