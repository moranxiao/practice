#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <windows.h>
//#include <stdlib.h>
//int main()
//{
//	char arr1[] = "hello bit !!!!";
//	char arr2[] = "##############";
//	int left = 0;
//	int right = strlen(arr2) - 1;
//	printf("%s\n", arr2);
//	while (left<= right)
//	{
//		Sleep(1000);
//		system("cls");
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//		printf("%s\n", arr2);
//	}
//	return 0;
//}
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void meau()
{
	printf("*****************************************\n");
	printf("*********     1. play      **************\n");
	printf("*********     0. exit      **************\n");
	printf("*****************************************\n");
}
void game()
{
	int n = rand()%100 +1;
	printf("请输入一个百位以内的数字\n");
	int a = 0;
	while (1)
	{
		scanf("%d", &a);
		if (a < n)
		{
			printf("猜小了\n");
		}
		else if( a > n)
		{
			printf("猜大了\n");

		}
		else
		{
			printf("猜对了\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
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
			printf("退出游戏\n");
			break;
		default :
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}