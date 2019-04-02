// Fill out your copyright notice in the Description page of Project Settings.

#include "Board.h"
#include "MyTypes.h"
#include "ChessField.h"
#include "Engine/World.h"
#include "Abstract_Piece.h"
#include "ChessPlayerController.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ABoard::ABoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	height = 8;
	width = 8;
	ActiveField = nullptr;



	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SpringArmAncor = CreateDefaultSubobject<USceneComponent>(TEXT("SpringArmAncor"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));	
	GameCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));

	SpringArmAncor->SetupAttachment(RootComponent);
	SpringArm->SetupAttachment(SpringArmAncor);
	GameCamera->SetupAttachment(SpringArm);
	
	SpringArmAncor->SetRelativeLocation(FVector(1600.f, -1200.f, 0.f));
	SpringArm->SetWorldRotation(FRotator(-50.f, 0.f, 0.f));

	SpringArm->TargetArmLength = 4000.f;
	SpringArm->bDoCollisionTest = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bInheritYaw = true;
	SpringArm->bInheritPitch = true;

	FigureAtPosition = { ECF::Tower, ECF::Horse, ECF::Bishop, ECF::Queen, ECF::King, ECF::Bishop,ECF::Horse, ECF::Tower,
						 ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn,
						 ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,
						 ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,
						 ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,
						 ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,ECF::Empty,
						 ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn, ECF::Pawn,
						 ECF::Tower, ECF::Horse, ECF::Bishop, ECF::Queen, ECF::King, ECF::Bishop,ECF::Horse, ECF::Tower 
						};


}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();

	// Get the Player Controller for later
	PC = Cast<AChessPlayerController>( UGameplayStatics::GetPlayerController(GetWorld(), 0));
	
	// set the Board to zero world position so that there are no problems with the camera positioning 
	SpringArm->SetWorldRotation(FRotator(-50.f, 0.f, 0.f));
	SetActorLocationAndRotation(FVector::ZeroVector, FRotator::ZeroRotator);

	FActorSpawnParameters Spawnparams;
	Spawnparams.Owner = this;

	F2DPosition tmpPos;
	FTransform tmpTrans(FRotator(0.f, 0.f, 0.f));

	// Spawn chess board
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++) {
			
			tmpTrans.SetLocation(FVector(x*400.f, y*-400.f, 0.f));
			tmpPos.x = x;
			tmpPos.y = y;
			
			auto tmp = GetWorld()->SpawnActorDeferred<AChessField>(FieldActor,tmpTrans,this,this);
		
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
			if( (x + y * width) < FigureAtPosition.Num() )
			{
				auto FigureType = FigureAtPosition[x + y * width];
			
				if(FigureType != ECF::Empty)
				{
					auto ClassToSpawn = Pieces.FindRef(FigureType);
					tmp->SpawnFigure(ClassToSpawn, x + y * width < 20 ? true : false);
					tmp->isOccupied = true;
				}
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

// Called to bind functionality to input
void ABoard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MouseYaw", this, &ABoard::MouseYaw);
	PlayerInputComponent->BindAxis("MousePitch", this, &ABoard::MousePitch);
	PlayerInputComponent->BindAxis("Zoom", this, &ABoard::Zoom);
	PlayerInputComponent->BindAction("LeftMouseClicked", IE_Pressed, this, &ABoard::LeftMouseClicked);
}

void ABoard::Zoom(float axis)
{	// invert the axis to change directions of zoom
	SpringArm->TargetArmLength = FMath::Clamp(SpringArm->TargetArmLength+ (-axis) * PC->ZoomSensitity, 2000.f,4000.f);
}

void ABoard::MousePitch(float axis)
{
	float MoveIntention = FMath::Clamp(SpringArm->GetTargetRotation().Pitch + axis * PC->MousePitchSensitivity, -60.f, -20.f);

	SpringArm->SetWorldRotation(FRotator(MoveIntention, SpringArm->GetTargetRotation().Yaw, 0.f));

	
}

void ABoard::MouseYaw(float axis) 
{
	SpringArmAncor->AddLocalRotation(FRotator(0.f,GetWorld()->GetDeltaSeconds() * axis *  PC->MouseYawSensitivity ,0.f));
}

void ABoard::LeftMouseClicked() 
{

	FHitResult Result; 
	GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursorByChannel
	(
		UEngineTypes::ConvertToTraceType(ECC_Camera),// trace channel - very obscure cast
		true,										 // complex trace 
		Result										 // output HitResult
	);


	auto ClickedFigure = Cast<AAbstract_Piece>(Result.Actor);

	if (ClickedFigure)		// if ChessPiece was clicked
	{
		// Deactivate the previous piece if any
		if (ActivePiece != nullptr)
		{
			ActivePiece->DeactivatePiece();
		}
		// set the new piece active
		ActivePiece = ClickedFigure;
		
		ActivePiece->ActivatePiece();

	}

}
