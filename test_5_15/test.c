#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//void test()
//{
//	static a = 1;
//	a++;
//	printf("%d ", a);
//}
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		test();
//	}
//	return 0;
//}
#include <stdio.h>

extern g_val;
int main()
{
	printf("%d ", g_val);
	return 0;
}