#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int my_strlen(char* p)
{
	char* pc = p;
	while (*pc != '\0')
	{
		pc++;
	}
	return pc - p; 
}
int main()
{
	char arr[] = "abc";
	int a = my_strlen(arr);
	printf("%d\n", a);
	return 0;
}