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
	printf("--------ɨ��-----------\n");
	PrintShow(show, ROW, COL);

}
int main()
{
	int input = 0;
	do
	{
		meau();
		printf("������ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ����\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}