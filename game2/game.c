#define _CRT_SECURE_NO_WARNINGS

#include "game.h"



void InitBoard(char board[ROWS][COLS], int row, int col, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}
void PrintShow(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (j = 0; j <= row; j++)
		printf("%d ", j);
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);

		for (j = 1; j <= col; j++)
		{
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}
}
