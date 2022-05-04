#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char ch = 0;
	while ((ch=getchar()) != EOF)
	{
		putchar(ch + 32);
		getchar();
	}
	return 0;
}