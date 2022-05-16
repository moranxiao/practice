#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int Add(int a, int b)
{
	int c = 0;
	c = a + b;
	return c;
}
int main()
{
	int a = 0;
	int b = 10;
	int c = 0;
	c = Add(a, b);
	return 0;
}