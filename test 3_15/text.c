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
//	printf("�������������\n");
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("������ȷ\n");
//			break;
//		}
//		else
//		{
//			printf("�����������������\n");
//
//		}
//
//	}
//	if (i = 3)
//	{
//		printf("�������");
//	}
//}
void game()
{
	int c = 0;
	int b = 0;
	c = rand() % 100 + 1;
	while (1)
	{   
		printf("�������\n");
		scanf("%d", &b);
		if (b < c)
			printf("��С��\n");
		else if (b > c)
			printf("�´���\n");
		else
		{
			printf("�¶���\n");
			break;
		}
	}
}
int meau()
{
	printf("*******************************************************\n");
	printf("*******************************************************\n");
	printf("*****************  1. ��ʼ��Ϸ  ***********************\n");
	printf("****************** 0.  �˳�     ***********************\n");
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
		printf("������\n");
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
			printf("����������\n");
			continue;
		}
	} while (a);
	printf("лл��������");
}