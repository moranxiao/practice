#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void meau()//�˵�����
{
	printf("*********************************\n");
	printf("******   1. play     ************\n");
	printf("*********************************\n");
	printf("******   0. exit     ************\n");
	printf("*********************************\n");

}
void game()
{
	char mine[ROWS][COLS] = { 0 };//��������
	char show[ROWS][COLS] = { 0 };//չʾʱ������
	InitBoard(mine, ROWS, COLS,'0');//���������ʼ��Ϊ�ַ�0
	InitBoard(show, ROWS, COLS, '*');//չʾʱ�������ʼ��Ϊ�ַ�*
	SetMine(mine, ROW, COL);//�����׵���������
	printf("--------ɨ��-----------\n");
	//PrintBoard(mine, ROW, COL);
	PrintBoard(show, ROW, COL);
	FindMine(mine,show, ROW, COL);//�������
}
int main()
{
	int input = 0;//����ѡ��ı���
	srand((unsigned int)time(NULL));//srand��������ȷ��rand���������ֵ����
	do
	{
		meau();//��ӡ�˵�
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
	} while (input);//���input�����ֵΪ0��ѭ����ֹͣ
	return 0;
}