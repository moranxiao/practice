#pragma warning(disable:4996)
//#include <stdio.h>
//#define SWAPINBIT(n) (((n)&0x55555555)<<1) | (((n)&0xaaaaaaaa)>>1)
//int main()
//{
//	char* p = "hello ""world\n";
//	printf("hello" " world\n");
//	printf("%s", p);
//	return 0;
//}
//#include <stdio.h>
//#define PRINT(FORMAT, VALUE) printf("the value of " #VALUE " is "FORMAT "\n", VALUE)
//int main()
//{
//	int i = 10;
//	PRINT("%d",i+3);
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int array[ARRAY_SIZE];
//	int i = 0;
//	for (i = 0; i < ARRAY_SIZE; i++)
//	{
//		array[i] = i;
//	}
//	for (i = 0; i < ARRAY_SIZE; i++)
//	{
//		printf("%d ", array[i]);
//	}
//	printf("\n");
//	return 0;
//}
//#include <stdio.h>
//#define __DEBUG__
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//#ifdef __DEBUG__
//		printf("%d\n", arr[i]);//为了观察数组是否赋值成功。
//#endif //__DEBUG__
//	}
//	return 0;
//}
//#include <stdio.h>
//int convertInteger(int A, int B) {
//    int count = 0;
//    A = A ^ B;
//    int i = 0;
//    for (i = 0; i < 32; i++)
//    {
//        if (A & (1 << i))
//            count++;
//    }
//    return count;
//}
//int main()
//{
//    printf("%d", convertInteger(15, 29));
//    return 0;
//}
#include <stdio.h>
int* intersection(int* arr1, int sz1, int* arr2, int sz2, int* retsz) {
    int i, j, k;
    *retsz = 0;
    int* ret = (int*)malloc((sz1 > sz2 ? sz2 : sz1) * 4);
    for (i = 0; i < sz1; i++)
    {
        for (j = 0; j < sz2; j++)
        {
            int flag = 0;
            if (arr1[i] == arr2[j])
            {
                for (k = 0; k < *retsz; k++)
                {
                    if (ret[k] == arr1[i])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ret[*retsz] = arr1[i];
                    *retsz++;
                }
            }
        }
    }
    return ret;
}