#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int i = 0;
	for (i = 1; (a * i) % b != 0; i++);
	printf("%d", a * i);
	return 0;
}