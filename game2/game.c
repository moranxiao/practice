#define _CRT_SECURE_NO_WARNINGS

#include "game.h"



void InitBoard(char board[ROWS][COLS], int row, int col, char set)//第四个参数为期望把数组设置成的字符
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
void PrintBoard(char board[ROWS][COLS], int row, int col)
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
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;//雷的数目
	while (count)
	{
		int x = rand() % row + 1;//产生1到row的随机数
		int y = rand() % col + 1;//产生1到col的随机数
		if (mine[x][y] == '0')//如果该坐标没有被设置过地雷则将其设置为地雷
		{
			mine[x][y] = '1';//地雷用字符1来表示
			count--;
		}
	}
}
char get_mine_count(char mine[ROWS][COLS], int x, int y)//求周围有多少雷的函数
{
	int i = 0;
	int j = 0;
	char count = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{//因为字符在内存中以ascii码的形式存储，所以如果周围有雷则可以用字符1减去字符0，得到ascii码值为1
		//然后将这些ascii码相加得到一个值
			count += mine[x + i][y + j] - '0';
		}
	}
	return count;//返回这个值
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	while (win < row*col - EASY_COUNT)//row*col - EASY_COUNT为需要有效扫雷的次数，每一次没扫到雷都会使win+1
	{
		int x = 0;
		int y = 0;
		printf("请输入排查的坐标>:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//判断坐标是否合法
		{
			if (show[x][y] == '*')//判断坐标是否被扫过，防止重复扫相同位置导致win多加了
			{
				if (mine[x][y] == '1')//判断坐标在地雷数组里是否为雷
				{
					printf("GAME OVER\n");
					PrintBoard(mine, ROW, COL);
					break;
				}
				else
				{
					remove_NoMine(mine,show, x, y);//显示周围雷的个数
					PrintBoard(show, ROW, COL);
					win++;//每一次扫到的不是雷都会使win++
				}
			}
			else
				printf("该坐标已被排除，不能重复排除\n");
		}
		else
			printf("输入坐标非法，请重新输入\n");
	}
	if (win == row * col - EASY_COUNT)//当win++到等于要扫的次数时，则游戏胜利
	{
		printf("恭喜你扫雷成功\n");
		PrintBoard(show, ROW, COL);
	}
}
//链式反应，如果输入坐标周围没有雷，则清除该坐标
void remove_NoMine(char mine[ROWS][COLS],char show[ROWS][COLS], int x, int y)
{
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)//判断坐标是否合法
	{
		int i = 0;
		int j = 0;
		show[x][y] = get_mine_count(mine, x, y) + '0';//将展示的数组里坐标更改为周围雷的个数
		if (show[x][y] == '0')
		{
			show[x][y] = ' ';//如果周围雷的个数为0,则设置此坐标为“空格”
			//判断此坐标周围坐标是否还有可设为空格的坐标 
			for (i = -1; i <= 1; i++)
			{
				for (j = -1; j <= 1; j++)
				{
					if (show[x+i][y+j] == '*')
						remove_NoMine(mine, show, x + i, y + j);//递归
				}
			}
		}
	}
}