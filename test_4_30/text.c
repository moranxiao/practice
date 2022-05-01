#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void* my_memmove(void* des, void* src, size_t num)
{
	void* ret = des;
	if (des < src)
	{
		while (num--)
			*((char*)des)++ = *((char*)src)++;
	 }
	else
	{
		while (num--)
			*((char*)des + num) = *((char*)src + num);
	}
	return ret;
}
int main()
{
	int arr[] = { 1, 2,3,4,5,6,7,8,9 };
	my_memmove(arr, arr + 3, 20);
	return 0;
}