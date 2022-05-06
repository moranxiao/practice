#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void meau()//菜单函数
{
	printf("*********************************\n");
	printf("******   1. play     ************\n");
	printf("*********************************\n");
	printf("******   0. exit     ************\n");
	printf("*********************************\n");

}
void game()
{
	char mine[ROWS][COLS] = { 0 };//地雷数组
	char show[ROWS][COLS] = { 0 };//展示时的数组
	InitBoard(mine, ROWS, COLS,'0');//地雷数组初始化为字符0
	InitBoard(show, ROWS, COLS, '*');//展示时的数组初始化为字符*
	SetMine(mine, ROW, COL);//放置雷到地雷数组
	printf("--------扫雷-----------\n");
	//PrintBoard(mine, ROW, COL);
	PrintBoard(show, ROW, COL);
	FindMine(mine,show, ROW, COL);//玩家找雷
}
int main()
{
	int input = 0;//输入选项的变量
	srand((unsigned int)time(NULL));//srand函数可以确定rand函数的随机值下限
	do
	{
		meau();//打印菜单
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
	} while (input);//如果input输入的值为0，循环会停止
	return 0;
}