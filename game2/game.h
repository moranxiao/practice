#pragma once

#include <stdio.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

void InitBoard(char board[ROWS][COLS], int row, int col, char set);

void PrintShow(char show[ROWS][COLS], int row, int col);