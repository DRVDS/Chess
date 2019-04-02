// Fill out your copyright notice in the Description page of Project Settings.

#include "ChessField.h"
#include "Abstract_Piece.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Board.h"
#include "Engine/World.h"
#include "MyTypes.h"

// Sets default values
AChessField::AChessField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FieldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = FieldMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> FieldMeshInst(TEXT("StaticMesh'/Game/StarterContent/Architecture/Floor_400x400.Floor_400x400'"));

	CenterOfBoard = CreateDefaultSubobject<USceneComponent>(TEXT("Center"));
	CenterOfBoard->SetupAttachment(RootComponent);
	CenterOfBoard->SetRelativeLocation(FVector(200.f, 200.f,0.f));

	// get material for field - black and white
	static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> WhiteInst(TEXT("MaterialInstanceConstant'/Game/Chess/White.White'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> BlackInst(TEXT("MaterialInstanceConstant'/Game/Chess/Black.Black'"));
	
	if (WhiteInst.Succeeded() && BlackInst.Succeeded() && FieldMeshInst.Succeeded())
	{
		FieldMesh->SetStaticMesh(FieldMeshInst.Object);
		White = WhiteInst.Object;
		Black = BlackInst.Object;
	}



}

void AChessField::SetFieldParameters(F2DPosition _Position, bool _isWhite)
{

	Position = _Position;
	isWhite = _isWhite;
	FieldMesh->SetMaterial(0, isWhite ? White : Black);
	
}

void AChessField::SpawnFigure(TSubclassOf<AAbstract_Piece> PieceToSpawn, bool isWhite)
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	auto Piece = GetWorld()->SpawnActor<AAbstract_Piece>(PieceToSpawn, CenterOfBoard->GetComponentTransform(),SpawnParams);
	if(Piece)
		Piece->FigureStaticMesh->SetMaterial(0, isWhite ? White : Black);
}

// Called when the game starts or when spawned
void AChessField::BeginPlay()
{
	Super::BeginPlay();

	// set parent
	this->Board = Cast<ABoard>(GetInstigator());

	// add delegate - needs to be done in BeginPlay
	FieldMesh->OnBeginCursorOver.AddDynamic(this, &AChessField::FieldOnBeginCursorOver);
	FieldMesh->OnEndCursorOver.AddDynamic(this, &AChessField::FieldOnEndCursorOver);

}
// TODO SET MATERIAL OUTLINE 
void AChessField::FieldOnBeginCursorOver(UPrimitiveComponent* Component) 
{
	if(Board->ActivePiece !=nullptr )
		GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Green, "CursorOver");

	TArray<AChessField> outValidFields;
	Board->ActivePiece->GetValidMoves(outValidFields);
	//turn on green outline
	FieldMesh->SetRenderCustomDepth(true);
}
// RESET  MATERIAL OUTLINE
void AChessField::FieldOnEndCursorOver(UPrimitiveComponent* Component)
{
	GEngine->AddOnScreenDebugMessage(1, 1.f, FColor::Red, "CursorLeft");
	//turn off green outline
	FieldMesh->SetRenderCustomDepth(false);
}
