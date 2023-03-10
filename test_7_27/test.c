//#pragma warning(disable:4996)
//#include <stdio.h>
//void  swap(int* arr, int a, int b)
//{
//    arr[a] = arr[a] ^ arr[b];
//    arr[b] = arr[a] ^ arr[b];
//    arr[a] = arr[a] ^ arr[b];
//}
//void rotate(int* nums, int sz, int k) {
//    k %= sz;
//    int i = 0;
//    while (k--)
//    {
//        for (i = sz - 1; i > 0; i--)
//        {
//            swap(nums, i, i - 1);
//        }
//    }
//}
//int main()
//{
//    int arr[] = { 1,3,4,5,6,7 };
//    rotate(arr, 6, 2);
//    return 0;
//}
#include<stdio.h>
#define MAXLINE 80
void zip(char* p)
{
	char* q = p;
	int n = 0;
	while (*p != '\0') {
		n = 1;
		while (*p == *(p + n)) {
			n++;
		}if (n >= 10) {
			*q++ = (n / 10) + '0';
			*q++ = (n % 10) + '0';
		}
		else if (n >= 2) {
			*q++ = n + '0';
		}
		*q++ = *(p + n - 1);
		p = p + n;
	}
	*q = '\0';
}
int main(void)
{
	char line[MAXLINE];
	printf("Input the string:");
	gets(line);
	zip(line);
	puts(line);
	return 0;
}