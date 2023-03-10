#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9//二维数组显示出来的行数
#define COL 9//二维数组显示出来的列数

#define ROWS ROW+2//二维数组的行数
#define COLS COL+2//二维数组的列数

#define EASY_COUNT 10//雷的个数


void InitBoard(char board[ROWS][COLS], int row, int col, char set);//初始化两个二维数组

void PrintBoard(char board[ROWS][COLS], int row, int col);//打印数组

void SetMine(char mine[ROWS][COLS], int row, int col);//放置雷

char get_mine_count(char mine[ROWS][COLS], int x, int y);//获取一个坐标周围雷的个数

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//玩家找雷

void remove_NoMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);//链式反应，如果输入坐标周围没有雷，则清除该坐标