#pragma warning(disable:4996)

#include "heap.h"

void test()
{
	Heap hp;
	HeapInit(&hp);
	HeapPush(&hp, 12);
	HeapPush(&hp, 20);
	HeapPush(&hp, 40);
	HeapPush(&hp, 2);
	HeapPush(&hp, 9);
	HeapPush(&hp, 7);
	HeapPush(&hp, 13);
	HeapPush(&hp, 1);
	HeapPush(&hp, 3);
	HeapPush(&hp, 6);
	HeapPush(&hp, 32);

	HeapPrint(&hp);
	printf("\n");
	HeapPop(&hp);
	HeapPrint(&hp);
	printf("\n");
	HeapPop(&hp);
	HeapPrint(&hp);
	printf("\n");
	HeapPop(&hp);
	HeapPrint(&hp);

}

//int main()
//{
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	if (i == 5)
//	//		continue;
//	//	printf("%d ", i);
//	//}
//	//int i = 0;
//	//while (i < 10)
//	//{
//	//	if (i == 5)
//	//		continue;
//	//	printf("%d ", i);
//	//	i++;
//	//}
//	//int i = 0;
//	//do {
//	//	if (i == 5)
//	//		continue;
//	//	printf("%d ", i);
//	//	i++;
//	//} while (i < 10);
//	return 0;
//}
//int main()
//{
//	double x = 3.6;
//	printf("%.50f\n", x);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	double x = 1.0;
//	double y = 0.1;
//	printf("%.50f\n", x - 0.9);
//	printf("%.50f\n", y);
//	if ((x - 0.9) == y) {
//		printf("you can see me!\n");
//	}
//	else{
//		printf("oops\n");
//	}
//	return 0;
//}

#include <stdio.h>
#include <math.h> //必须包含math.h,要不然无法使用fabs
#include <float.h> //必须包含，要不然无法使用系统精度
int main()
{
	double x = 1.0;
	double y = 0.1;
	printf("%.50f\n", x - 0.9);
	printf("%.50f\n", y);
	if (fabs((x - 0.9) - y) < DBL_EPSILON) { //原始数据是浮点数，我们就用DBL_EPSILON
		printf("you can see me!\n");
	} 
	else{
		printf("oops\n");
	} 
	return 0;
}