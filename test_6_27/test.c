#pragma warning(disable:4996)
#include <stdio.h>
#include <assert.h>
	void* my_memmove(void* dest,const void* src,size_t num)
	{
		void* ret = dest;
		if (src > dest)
		{
			while (num--)
			{
				*(char*)dest = *(char*)src;
				dest = (char*)dest + 1;
				src = (char*)src + 1;
			}
		}
		else
		{
			while (num--)
			{
				*((char*)dest + num) = *((char*)src + num);
			}
		}
		return ret;
	}
int main()
{
	char arr[] = "abcabcdefghjk";
	printf("%s", (char*)my_memmove(arr,arr+3,5));
	return 0;
}