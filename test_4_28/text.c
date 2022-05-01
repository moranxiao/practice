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
		printf("���ʤ��\n");
	if (is_win(board, ROW, COL) == '#')
		printf("����ʤ��\n");
	if (is_win(board, ROW, COL) == 'C')
		printf("ƽ��\n");
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
		printf("������ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
				game();
			break;
		case 0:
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}