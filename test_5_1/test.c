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
	char board[ROW][COL] = { 0 };//�������̶�ά����
	init_board(board,ROW, COL);//��ʼ����ά����Ϊ�ո�
	print_board(board, ROW, COL);//��ӡ����
	while (1)
	{
		player(board, ROW, COL);
		print_board(board, ROW, COL);//��ӡ����
		if (is_win(board, ROW, COL) != 'C')
			break;
		computer(board, ROW, COL);
		print_board(board, ROW, COL);//��ӡ����
		if (is_win(board, ROW, COL) != 'C')
			break;
	}
	if (is_win(board, ROW, COL) == '*')
		printf("���ʤ��\n");
	if (is_win(board, ROW, COL) == '#')
		printf("����ʤ��\n");
	if (is_win(board, ROW, COL) == 'Q')
		printf("ƽ��\n");
	Sleep(3000);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;//�˵�ѡ���
	do//��do while ѭ����һ�ο���ֱ�ӽ���ѭ�����ڶ��β���Ҫ�ж�������������ֱ�Ӵ�ӡ�˵�
	{
		system("cls");
		meau();//�˵�����
		printf("������ѡ��>:");
		scanf("%d", &input);//����ѡ��
		switch (input)
		{
		case 1://play
			game();//ʵ����������Ϸ�ĺ���
			break;
		case 0://exit
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);//���ѡ���Ϊ0�������ѭ����Ϊ���������
	return 0;
}