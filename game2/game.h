#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9//��ά������ʾ����������
#define COL 9//��ά������ʾ����������

#define ROWS ROW+2//��ά���������
#define COLS COL+2//��ά���������

#define EASY_COUNT 10//�׵ĸ���


void InitBoard(char board[ROWS][COLS], int row, int col, char set);//��ʼ��������ά����

void PrintBoard(char board[ROWS][COLS], int row, int col);//��ӡ����

void SetMine(char mine[ROWS][COLS], int row, int col);//������

char get_mine_count(char mine[ROWS][COLS], int x, int y);//��ȡһ��������Χ�׵ĸ���

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//�������

void remove_NoMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);//��ʽ��Ӧ���������������Χû���ף������������