#pragma warning(disable:4996)
#include <stdio.h>
void* my_memcpy(void* dest, void* src,int num)
{
	assert(dest && src);
	void* ret = dest;
	while (num--)
	{
		*((char*)dest)++ = *((char*)src)++;
	}
	return ret;
}
int main()
{
	return 0;
}