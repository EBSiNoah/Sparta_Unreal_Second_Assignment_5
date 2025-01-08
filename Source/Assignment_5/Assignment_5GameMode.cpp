// Copyright Epic Games, Inc. All Rights Reserved.

#include "Assignment_5GameMode.h"
#include "Assignment_5Character.h"
#include "UObject/ConstructorHelpers.h"

AAssignment_5GameMode::AAssignment_5GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
