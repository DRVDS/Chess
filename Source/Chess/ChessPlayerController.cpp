// Fill out your copyright notice in the Description page of Project Settings.

#include "ChessPlayerController.h"
#include "Board.h"
#include "Kismet/GameplayStatics.h"

void AChessPlayerController::BeginPlay()
{
	TArray<AActor*> FoundBoards;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),ABoard::StaticClass(), FoundBoards);
	// There will only be one board

	if (FoundBoards.Num() > 0)
		MyBoard = Cast<ABoard>(FoundBoards[0]);
	else
		UE_LOG(LogTemp, Warning, TEXT("No chess board found"));

	// use the Camera of the board
	SetViewTargetWithBlend(MyBoard);

}

void AChessPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MouseYaw", this, &AChessPlayerController::MouseYaw);
	InputComponent->BindAxis("MousePitch", this, &AChessPlayerController::MousePitch);
	//InputComponent->BindAxis("Zoom", this, &AChessPlayerController::Zoom);
}



void AChessPlayerController::MouseYaw(float axis) {
	MyBoard->AxisValueYaw = axis;
}

void AChessPlayerController::MousePitch(float axis) {
	MyBoard->AxisValuePitch = axis;
}
	//FRotator current = MyBoard->SpringArmAncor->GetComponentRotation();
	//current.Pitch += axis;
	//MyBoard->SpringArmAncor->SetWorldRotation(FRotator(current.Pitch, current.Yaw, current.Roll));

