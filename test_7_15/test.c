#pragma warning(disable:4996)
#include <stdio.h>
int main()
{
	////练习1
	//struct S1
	//{
	//	char c1;
	//	int i;
	//	char c2;
	//};
	//printf("%d\n", sizeof(struct S1));
	////练习2
	//struct S2
	//{
	//	char c1;
	//	char c2;
	//	int i;
	//};
	//printf("%d\n", sizeof(struct S2));
	////练习3
	//struct S3
	//{
	//	double d;
	//	char c;
	//	int i;
	//};
	//printf("%d\n", sizeof(struct S3));
	////练习4-结构体嵌套问题
	//struct S4
	//{
	//	char c1;
	//	struct S3 s3;
	//	double d;
	//};
	//printf("%d\n", sizeof(struct S4));
	//struct A
	//{
	//	int _a : 2;
	//	int _b : 2;
	//	int _c : 10;
	//	int _d : 30;
	//}a;
	//printf("%zu", sizeof(a));
	union Un
	{
		int i;
		char c;
	};
	union Un un;
	// 下面输出的结果是一样的吗？
	printf("%d\n", &(un.i));
	printf("%d\n", &(un.c));
	//下面输出的结果是什么？
	un.i = 0x11223344;
	un.c = 0x55;
	printf("%x\n", un.i);
	return 0;
}