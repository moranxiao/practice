#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	float a = 2;
	float b = 1;
	int i = 1;
	float t = 0;
	float ret = 0;
	for (i = 1; i <= 20; i++)
	{
		ret = ret + a / b;
		t = a;
		a = a + b;
		b = t;
	}
	printf("%f\n", ret);
}