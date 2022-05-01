#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define ROW 3
#define COL 3

void init_board(char board[ROW][COL], int row, int col);

void print_board(char board[ROW][COL], int row, int col);

void player(char board[ROW][COL], int row, int col);

void computer(char board[ROW][COL], int row, int col);

char is_win(char board[ROW][COL], int row, int col);

int IsFull(char board[ROW][COL], int row, int col);