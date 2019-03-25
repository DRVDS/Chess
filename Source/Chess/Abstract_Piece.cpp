// Fill out your copyright notice in the Description page of Project Settings.

#include "Abstract_Piece.h"

// Sets default values
AAbstract_Piece::AAbstract_Piece()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAbstract_Piece::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbstract_Piece::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAbstract_Piece::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

