#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <assert.h>
//int my_strlen(const char* scr)
//{
//	assert(scr != NULL);
//	int count = 0;
//	while (*scr++)
//	{
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	printf("%d\n", my_strlen("abcd"));
//	return 0;
//}
//#include <stdio.h>
//#include <assert.h>
//char* my_strcpy(char* dest,const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[] = "###########";
//	char arr2[] = "abc";
//	printf("%s\n", my_strcpy(arr1, arr2));
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int arr1[20] = { 0 };
//	int i = 0;
//	while (scanf("%d", &arr1[i]) != EOF)
//	{
//		i++;
//	}
//	int arr2[20] = { 0 };
//	int j = 0;
//	int k = 0;
//	for (i = 0; i < 20; i++)
//	{
//		if (arr1[i] % 2 == 1)//判断数组中元素是否为奇数，奇数则排在前面；偶数则存储于arr2数组中
//			arr1[j++] = arr1[i];
//		else
//			arr2[k++] = arr1[i];
//	}
//	for (i = 0; i < k; i++)
//	{
//		arr1[j++] = arr2[i];//将arr2数组中元素导入arr1
//	}
//	for (i = 0; i < 20; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}
int add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}
int main()
{
	int a = 10;
	int b = 20;
	int c = 0;
	c = add(a, b);
	return c;
}