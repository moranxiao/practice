#define _CRT_SECURE_NO_WARNINGS

#include "game.h"
void meau()
{
	printf("*************************************\n");
	printf("**********    1.paly     ************\n");
	printf("**************************************\n");
	printf("**********    0.exit     *************\n");
	printf("**************************************\n");
}
void game()
{
	srand((unsigned int)time(NULL));
	char board[ROW][COL] = { 0 };
	init_board(board, ROW, COL);
	print_board(board, ROW, COL);
	while (1)
	{

		player(board,ROW,COL);
		if (is_win(board, ROW, COL) != 'Q')
			break;
		print_board(board, ROW, COL);
		computer(board,ROW,COL);
		print_board(board, ROW, COL);
		if (is_win(board, ROW, COL) != 'Q')
			break;
	}
	if (is_win(board, ROW, COL) == '*')
		printf("玩家胜利\n");
	if (is_win(board, ROW, COL) == '#')
		printf("电脑胜利\n");
	if (is_win(board, ROW, COL) == 'C')
		printf("平局\n");
	print_board(board, ROW, COL);
	Sleep(3000);
}
int main()
{
	int input = 0;
	do
	{
		system("cls");
		meau();
		printf("请输入选项>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
				game();
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}