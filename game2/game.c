#define _CRT_SECURE_NO_WARNINGS

#include "game.h"



void InitBoard(char board[ROWS][COLS], int row, int col, char set)//���ĸ�����Ϊ�������������óɵ��ַ�
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
	int count = EASY_COUNT;//�׵���Ŀ
	while (count)
	{
		int x = rand() % row + 1;//����1��row�������
		int y = rand() % col + 1;//����1��col�������
		if (mine[x][y] == '0')//���������û�б����ù�������������Ϊ����
		{
			mine[x][y] = '1';//�������ַ�1����ʾ
			count--;
		}
	}
}
char get_mine_count(char mine[ROWS][COLS], int x, int y)//����Χ�ж����׵ĺ���
{
	int i = 0;
	int j = 0;
	char count = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{//��Ϊ�ַ����ڴ�����ascii�����ʽ�洢�����������Χ������������ַ�1��ȥ�ַ�0���õ�ascii��ֵΪ1
		//Ȼ����Щascii����ӵõ�һ��ֵ
			count += mine[x + i][y + j] - '0';
		}
	}
	return count;//�������ֵ
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	while (win < row*col - EASY_COUNT)//row*col - EASY_COUNTΪ��Ҫ��Чɨ�׵Ĵ�����ÿһ��ûɨ���׶���ʹwin+1
	{
		int x = 0;
		int y = 0;
		printf("�������Ų������>:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�ж������Ƿ�Ϸ�
		{
			if (show[x][y] == '*')//�ж������Ƿ�ɨ������ֹ�ظ�ɨ��ͬλ�õ���win�����
			{
				if (mine[x][y] == '1')//�ж������ڵ����������Ƿ�Ϊ��
				{
					printf("GAME OVER\n");
					PrintBoard(mine, ROW, COL);
					break;
				}
				else
				{
					remove_NoMine(mine,show, x, y);//��ʾ��Χ�׵ĸ���
					PrintBoard(show, ROW, COL);
					win++;//ÿһ��ɨ���Ĳ����׶���ʹwin++
				}
			}
			else
				printf("�������ѱ��ų��������ظ��ų�\n");
		}
		else
			printf("��������Ƿ�������������\n");
	}
	if (win == row * col - EASY_COUNT)//��win++������Ҫɨ�Ĵ���ʱ������Ϸʤ��
	{
		printf("��ϲ��ɨ�׳ɹ�\n");
		PrintBoard(show, ROW, COL);
	}
}
//��ʽ��Ӧ���������������Χû���ף������������
void remove_NoMine(char mine[ROWS][COLS],char show[ROWS][COLS], int x, int y)
{
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)//�ж������Ƿ�Ϸ�
	{
		int i = 0;
		int j = 0;
		show[x][y] = get_mine_count(mine, x, y) + '0';//��չʾ���������������Ϊ��Χ�׵ĸ���
		if (show[x][y] == '0')
		{
			show[x][y] = ' ';//�����Χ�׵ĸ���Ϊ0,�����ô�����Ϊ���ո�
			//�жϴ�������Χ�����Ƿ��п���Ϊ�ո������ 
			for (i = -1; i <= 1; i++)
			{
				for (j = -1; j <= 1; j++)
				{
					if (show[x+i][y+j] == '*')
						remove_NoMine(mine, show, x + i, y + j);//�ݹ�
				}
			}
		}
	}
}