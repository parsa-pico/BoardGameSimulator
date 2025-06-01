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
