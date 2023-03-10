#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void init_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void print_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (j = 0; j < row; j++)
	{
		for (i = 0; i < col; i++)
		{
			if (i < col - 1)
				printf(" %c |", board[j][i]);
			else
				printf(" %c ", board[j][i]);
			
		}
		printf("\n");
		if (j < col - 1)
		{
			for (i = 0; i < col; i++)
			{
				if (i < col - 1)
					printf("---|");
				else
					printf("---");
			}
			printf("\n");
	    }
		

	}
}

void player(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("玩家下棋>:");
	while (1)
	{
		printf("请输入下棋的坐标:>");
		scanf("%d %d", &i, &j);
		if (i <= row && i > 0 && j <= col && j > 0)
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
			}
			else
				printf("坐标已被占用，请重新输入\n");
		}
		else
			printf("坐标非法，请重新输入\n");
	}
}
void computer(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("电脑下棋>:\n");
	while (1)
	{
		i = rand() % row;
		j = rand() % col;
		if (board[i ][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}	
	}
}
int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)
	{ 
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}

	if (board[0][0] == board[1][1] && board[2][2] == board[1][1]&&board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (is_full(board, ROW, COL))
		return 'C';
	return 'Q';
}