#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 12;
//	int* p1 = &a;
//	int* p2 = &b;
//	int* arr[2] = { p1,p2 };
//	printf("%d %d\n", *arr[0], *arr[1]);
//	return 0;
//}
//#include <stdio.h>
//#include <math.h>
//float fun(float a, float b, float c)
//{
//	float p = (a + b + c) / 2;
//	if (a + b > c && a + c > b && b + c > a)
//		return sqrt(p * (p - a)*(p - b)*(p - c));
//	else
//		return 0;
//}
//int main()
//{
//	float a, b, c;
//	scanf("%f %f %f", &a, &b, &c);
//	if (fun(a, b, c) != 0)
//		printf("%f", fun(a, b, c));
//	else
//		printf("不能构成三角形");
//	return 0;
//}
//#include <stdio.h>
//int fun(int a[10], int sz)
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (a[i] % 2 == 0)
//			sum += a[i];
//	}
//	return sum;
//}
//int main()
//{
//	int  a[10] = { 2,1,3,4,5,6,0,8,9,7 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	printf("%d\n",fun(a, sz));
//	return 0;
//}
//#include <stdio.h>
//void fun(int a[3][5], int b[3])
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int max = a[i][0];
//		for (j = 0; j < 5; j++)
//		{
//			if (max < a[i][j])
//			{
//				int t = a[i][j];
//				a[i][j] = max;
//				max = t;
//			}
//		}
//		b[i] = max;
//	}
//}
//int main()
//{
//	int a[3][5] = { 1, 2 ,3, 4 , 5,2,3,6,3,2,5,9,0,2,1 };
//	int b[3] = { 0 };
//	fun(a,b);
//}
//#include <stdio.h>
//fun(int x)
//{
//	return 0;
//}
//int main()
//{
//	int x = 0;
//	printf("\nThe result :\n", fun(x));
//}
//#include < stdio.h >
//struct S
//{
//	int a;
//	int b;
//};
//int main()
//{
//	struct S a, * p = &a;
//	a.a = 99;
//	printf("%d\n",a.a  );
//	return 0;
//}
#include <stdio.h>
int main()
{
	int money = 0;
	int total = 0;
	int empty = 0;
	scanf("%d", &money);
	total = money;
	empty = total;
	while (empty > 1)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("%d\n",total);
	return 0;
}