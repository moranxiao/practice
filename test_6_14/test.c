#include <stdio.h>

int findnum(int a[][3], int x, int y, int f) //��һ��������������Ҫ����
{
	int i = 0, j = x - 1; //�����Ͻǿ�ʼ����

	while (j >= 0 && i < y)
	{
		if (a[i][j] < f) //���Ҵ������
		{
			i++;
		}
		else if (a[i][j] > f) //����С������
		{
			j--;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int a[][3] = { {1, 3, 5},
				  {3, 5, 7},
				  {5, 7, 9} }; //һ��ʾ��

	if (findnum(a, 3, 3, 2))
	{
		printf("It has been found!\n");
	}
	else
	{
		printf("It hasn't been found!\n");
	}

	return 0;
}
