#pragma warning(disable:4996)

#include<stdio.h>
#define NUM 10
int main()
{
	int arr[NUM] = { 0 };
	int i = 0;
	int n = NUM / 2;
	int count = 0;
	for (i = 0; i < NUM; i++)
		scanf("%d", &arr[i]);
	int* p1, * p2;
	p1 = &arr;
	p2 = &arr;
	for (i = 0; i < NUM; i++) {
		p2 = &arr[i];
		count = 1;
		while (p2 <= &arr[NUM - 1]) {
			p2++;
			if (*p1 == *p2) {
				count++;
			}
		}
		if (count > n) {
			printf("%d %d\n", count, arr[i]);
		}
		p1++;
	}
	return 0;
}