#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
long fun(char* p)
{
	while (*p++)
	{
		;
	}


}
int main()
{
	char arr[100] = "-1234";
	fun(arr);
	return 0;
}