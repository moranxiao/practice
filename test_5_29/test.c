#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void fun(void)
{
	static a = 1;
	a++;
	printf("%d ", a);
}
int main()
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		fun();
	}
	return 0;
}