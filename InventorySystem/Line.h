﻿#pragma once

#include "Line.generated.h"

USTRUCT(BlueprintType)

//用于绘制背包界面的线
struct FLine
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D Start;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D End;

	FLine() : Start(FVector2D::ZeroVector), End(FVector2D::ZeroVector) {}
	FLine(FVector2D start, FVector2D end) : Start(start), End(end) {}
};
