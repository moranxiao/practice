#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void meau()
{
	printf("******************************************\n");
	printf("**********     1.play     ****************\n");
	printf("******************************************\n");
	printf("**********     0.exit     ****************\n");
	printf("******************************************\n");

}
void game()
{
	char board[ROW][COL] = { 0 };//定义棋盘二维数组
	init_board(board,ROW, COL);//初始化二维数组为空格
	print_board(board, ROW, COL);//打印棋盘
	while (1)
	{
		player(board, ROW, COL);
		print_board(board, ROW, COL);//打印棋盘
		if (is_win(board, ROW, COL) != 'C')
			break;
		computer(board, ROW, COL);
		print_board(board, ROW, COL);//打印棋盘
		if (is_win(board, ROW, COL) != 'C')
			break;
	}
	if (is_win(board, ROW, COL) == '*')
		printf("玩家胜利\n");
	if (is_win(board, ROW, COL) == '#')
		printf("电脑胜利\n");
	if (is_win(board, ROW, COL) == 'Q')
		printf("平局\n");
	Sleep(3000);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;//菜单选项函数
	do//用do while 循环第一次可以直接进入循环，第二次才需要判断条件，有利于直接打印菜单
	{
		system("cls");
		meau();//菜单函数
		printf("请输入选项>:");
		scanf("%d", &input);//输入选项
		switch (input)
		{
		case 1://play
			game();//实现三子棋游戏的函数
			break;
		case 0://exit
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);//如果选项函数为0，则结束循环，为其他则继续
	return 0;
}