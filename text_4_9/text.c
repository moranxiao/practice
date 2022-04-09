#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<assert.h>
size_t my_strlen(const char* p)
{
	size_t i = 0;
	assert(p != NULL);
	while (*p++)
	{
		i++;
	}
	return i;
}
int main()
{
	char arr[] = "hello bit";
	printf("%d",my_strlen(arr));
	return 0;
}double * (*p)[5]