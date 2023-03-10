#pragma warning(disable:4996)
//#include <stdio.h>
//int g_arr[2];
//void uni_num(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int count = 0;
//		for (j = 0; j < sz; j++)
//		{
//			if (arr[i] == arr[j])
//				count++;
//		}
//		if (count == 1)
//		{
//			g_arr[k++] = arr[i];
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 0, 0, 1, 1, 2, 2, 3, 4, 6, 6, 7, 7};
//    uni_num(arr, sizeof(arr));
//	printf("%d %d", g_arr[0], g_arr[1]);
//	return 0;
//}
#include <stdio.h>
#include <assert.h>
//char* my_strncpy(char* dest, const char* src, size_t count)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (count--)
//	{
//		*dest++ = *src++;
//	}
//	return ret;
//}
char* my_strncat(char* dest, const char* src, size_t count)
{
	assert(dest && src);
	char* ret = dest;
	while (*dest)
	{
		dest++;
	}
	while (count--)
	{
		if (*src != '\0')
			*dest++ = *src++;
		else
			break;
	}
	return ret;
}
int main()
{
	char arr1[20] = "#########";
	printf("%s", my_strncat(arr1, "abc", 4));
	return 0;
}