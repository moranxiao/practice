#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//void text()
//{
//	printf("**************************************\n");
//	printf("********** 1.add  2.sub **************\n");
//	printf("********** 3.mul  4.div **************\n");
//	printf("**********    0.exit    **************\n");
//	printf("**************************************\n");
//}
//int main()
//{
//	int input = 0;
//	int x, y;
//	int (*arr[])(int, int) = { 0, add, sub, mul, div };
//	do {
//		text();
//		printf("请选择计算方式>:");
//		scanf("%d", &input);
//		if (input <= 4 && input >= 1)
//		{
//			printf("请输入想计算的两个数>:");
//			scanf("%d %d", &x, &y);
//			printf("%d\n", arr[input](x, y));
//		}
//	} while (input);
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//void rep(void* e1, void* e2, size_t width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *((char*)e1 + i);
//	   *((char*)e1 + i) = *((char*)e2 + i);
//	   *((char*)e2 + i) = tmp;
//	}
//}
//void bubble_sort(void* base, size_t sz,size_t width,int (*cmp)(const void* ,const void*))
//{
//	int i = 0;
//	int j = 0;
//	int flag = 1;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp((char*)base+j*width,(char*)base+(j+1)*width)>0)
//			{
//				rep((char*)base + j * width, (char*)base + (j + 1) * width,width);
//				flag = 0;
//			}
//		}
//		if (flag)
//			break;
//	}
//}
//int cmp_arr1(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//int cmp_arr2(const void* e1, const void* e2)
//{
//	return *(char*)e1 - *(char*)e2;
//}
//struct stu
//{
//	char name[20];
//	int age;
//};
//int cmp_stu_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
//}
//int cmp_stu_age(const void* e1, const void* e2)
//{
//	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
//}
//int main()
//{
//	int arr1[] = { 9,8,7,6,5,4,3,2,1 };
//	char arr2[] = "fedcba";
//	struct stu s[] = { {"xiaoming",20},{ "xiaozhang", 19 } ,{ "xiaowang", 21 } };
//	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
//	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
//	int sz3 = sizeof(s) / sizeof(s[0]);
//
//	bubble_sort(arr1, sz1, sizeof(arr1[0]), cmp_arr1);
//	bubble_sort(arr2, sz2-1, sizeof(arr2[0]), cmp_arr2);
////	qsort(s, sz3, sizeof(s[0]), cmp_stu_name);
//	bubble_sort(s, sz3, sizeof(s[0]), cmp_stu_age);
//
//	return 0;
//}
#include <stdio.h>
#include <string.h>
int is_revolve(char str1[], char str2[], size_t sz)
{
	int i = 0;
	for (i = 0; i < sz; i++) {
		int j = 0;
		for (j = 0; j < sz - 1; j++){
			char tmp = str1[j];
			str1[j] = str1[j + 1];
			str1[j + 1] = tmp;
		}
		if (!strcmp(str1, str2))
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	char str1[] = "AABCD";
	char str2[] = "BCDAA";
	if (is_revolve(str1, str2, strlen(str1)))
		printf("是");
	else
		printf("不是");
	return 0;
}