#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void meau()
{
	printf("*********************************\n");
	printf("******   1. play     ************\n");
	printf("*********************************\n");
	printf("******   0. exit     ************\n");
	printf("*********************************\n");

}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS, '*');
	printf("--------扫雷-----------\n");
	PrintShow(show, ROW, COL);

}
int main()
{
	int input = 0;
	do
	{
		meau();
		printf("请输入选项>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}