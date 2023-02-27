// Copyright Epic Games, Inc. All Rights Reserved.


#include "GeometrySandBoxGameModeBase.h"
#include "SandboxPawn.h"
#include "SandboxPlayerController.h"

AGeometrySandBoxGameModeBase::AGeometrySandBoxGameModeBase()
{
	DefaultPawnClass = ASandboxPawn::StaticClass();
	PlayerControllerClass = ASandboxPlayerController::StaticClass();
}
