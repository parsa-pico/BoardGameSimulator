// Fill out your copyright notice in the Description page of Project Settings.


#include "TileUtility.h"

TArray<int32> UTileUtility::GetAdjacentIndices(int32 Index, int32 Rows, int32 Cols, bool bIncludeDiagonals)
{
	TArray<int32> Adjacent;

	const int32 Row = Index / Cols;
	const int32 Col = Index % Cols;

	if (Row > 0)
		Adjacent.Add(Index - Cols);
	if (Row < Rows - 1)
		Adjacent.Add(Index + Cols);
	if (Col > 0)
		Adjacent.Add(Index - 1);
	if (Col < Cols - 1)
		Adjacent.Add(Index + 1);

	if (bIncludeDiagonals)
	{
		if (Row > 0 && Col > 0)
			Adjacent.Add(Index - Cols - 1);
		if (Row > 0 && Col < Cols - 1)
			Adjacent.Add(Index - Cols + 1);
		if (Row < Rows - 1 && Col > 0)
			Adjacent.Add(Index + Cols - 1);
		if (Row < Rows - 1 && Col < Cols - 1)
			Adjacent.Add(Index + Cols + 1);
	}

	return Adjacent;
}
TArray<int32> UTileUtility::GetTilesAtMaxDistance(int32 Index, int32 Rows, int32 Cols, int32 MaxDistance)
{
	TSet<int32> Result;  // Use set to prevent duplicates
	if (MaxDistance <= 0)
		return Result.Array();

	const int32 StartRow = Index / Cols;
	const int32 StartCol = Index % Cols;

	for (int32 Distance = 1; Distance <= MaxDistance; ++Distance)
	{
		for (int32 dRow = -Distance; dRow <= Distance; ++dRow)
		{
			int32 dCol = Distance - FMath::Abs(dRow);  // |dRow| + |dCol| == Distance

			// Check left
			int32 NewRow = StartRow + dRow;
			int32 NewColLeft = StartCol - dCol;
			if (NewRow >= 0 && NewRow < Rows && NewColLeft >= 0 && NewColLeft < Cols)
				Result.Add(NewRow * Cols + NewColLeft);

			// Check right (avoid duplicate if dCol == 0)
			if (dCol != 0)
			{
				int32 NewColRight = StartCol + dCol;
				if (NewRow >= 0 && NewRow < Rows && NewColRight >= 0 && NewColRight < Cols)
					Result.Add(NewRow * Cols + NewColRight);
			}
		}
	}

	return Result.Array();
}

