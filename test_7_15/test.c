#pragma warning(disable:4996)
#include <stdio.h>
int main()
{
	////��ϰ1
	//struct S1
	//{
	//	char c1;
	//	int i;
	//	char c2;
	//};
	//printf("%d\n", sizeof(struct S1));
	////��ϰ2
	//struct S2
	//{
	//	char c1;
	//	char c2;
	//	int i;
	//};
	//printf("%d\n", sizeof(struct S2));
	////��ϰ3
	//struct S3
	//{
	//	double d;
	//	char c;
	//	int i;
	//};
	//printf("%d\n", sizeof(struct S3));
	////��ϰ4-�ṹ��Ƕ������
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
	// ��������Ľ����һ������
	printf("%d\n", &(un.i));
	printf("%d\n", &(un.c));
	//��������Ľ����ʲô��
	un.i = 0x11223344;
	un.c = 0x55;
	printf("%x\n", un.i);
	return 0;
}