#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <windows.h>
//int main()
//{
//	char arr1[] = "welcome to china";
//	char arr2[] = "################";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	while (right >= left)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		system("cls");
//		right--;
//		left++;
//	}
//	printf("%s", arr2);
//}
//int main()
//{
//	char password[20] ="0";
//	int  i = 0;
//	printf("请输入你的密码\n");
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("输入正确\n");
//			break;
//		}
//		else
//		{
//			printf("输入错误，请重新输入\n");
//
//		}
//
//	}
//	if (i = 3)
//	{
//		printf("输入禁锢");
//	}
//}
void game()
{
	int c = 0;
	int b = 0;
	c = rand() % 100 + 1;
	while (1)
	{   
		printf("请猜数字\n");
		scanf("%d", &b);
		if (b < c)
			printf("猜小了\n");
		else if (b > c)
			printf("猜大了\n");
		else
		{
			printf("猜对了\n");
			break;
		}
	}
}
int meau()
{
	printf("*******************************************************\n");
	printf("*******************************************************\n");
	printf("*****************  1. 开始游戏  ***********************\n");
	printf("****************** 0.  退出     ***********************\n");
	printf("*******************************************************\n");
	printf("*******************************************************\n");
}
int main()
{
	srand((unsigned int)time(NULL));
	int a;
	do
	{    
		meau();
		printf("请输入\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
		{
			game();
			break;
		}
		case 0:
		{
			break;
		}
		}
		if (a != 1 || a != 0)
		{
			printf("请重新输入\n");
			continue;
		}
	} while (a);
	printf("谢谢您的游玩");
}