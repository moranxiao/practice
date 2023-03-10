#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <assert.h>
//
//char* my_strstr(const char* str1,const char* str2)
//{
//	assert(str1 && str2);
//	const char* s1 = NULL;
//	const char* s2 = NULL;
//	while (*str1)
//	{
//		s1 = str1;
//		s2 = str2;
//		while ( *s1 && *s2  &&*s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (!(*s2))
//			return (char*)str1;
//		str1++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[] = "abbbcdefg";
//	char arr2[] = "dfg";
//	printf("%s ",my_strstr(arr1, arr2));
//}
//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[n];
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d",&arr[i]);
//	}
//	int max = 0;
//	int min = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (arr[max] < arr[i])
//			max = i;
//		if (arr[min] > arr[i])
//			min = i;
//		
//	}
//	printf("%d", arr[max] - arr[min]);
//}
//#include <stdio.h>
//int main()
//{
//	char a = 0;
//	while ((scanf("%c", &a)) != EOF)
//	{
//		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
//			printf("%c is an alphabet.\n", a);
//		else
//			printf("%c is not an alphabet.\n", a);
//		getchar();
//	}
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int arr[3] = { 0 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int max = 0;
//	for (i = 0; i < 3; i++)
//	{
//		if (arr[max] < arr[i])
//			max = i;
//	}
//	printf("%d", arr[max]);
//}
#include <stdio.h>
int is_Lily(int n)
{
	return n % 10 * n / 10 + n % 100 * n / 100 + n % 1000 * n / 1000 + n % 10000 * n / 10000;
}
int main()
{
	int n = 0;
	for (n = 10000; n < 100000; n++)
	{
		if((is_Lily(n))==n)
		printf("%d ",is_Lily(n));
	}
	return 0;
}