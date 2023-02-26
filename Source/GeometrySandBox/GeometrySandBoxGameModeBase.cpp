// Copyright Epic Games, Inc. All Rights Reserved.


#include "GeometrySandBoxGameModeBase.h"
#include "SandboxPawn.h"

AGeometrySandBoxGameModeBase::AGeometrySandBoxGameModeBase()
{
	DefaultPawnClass = ASandboxPawn::StaticClass();
}
