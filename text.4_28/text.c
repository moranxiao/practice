#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int step(int n)
//{
//    if (n > 2)
//        return step(n - 1) + step(n - 2);
//    else if (2 == n)
//        return 2;
//    else
//        return 1;
//}
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    printf("%d",step(n));
//}
#include <stdio.h>
int main()
{
	int N = 0;
	scanf("%d", &N);
	int arr[N];
	int i = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	for (i = 0; i < N; i++)
	{
		if (arr[i] == n)
			continue;
		printf("%d ", arr[i]);			
	}
}