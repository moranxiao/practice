#pragma warning(disable:4996)
//#include <stdio.h>
//enum 
//{
//	RED=1,
//	GREEN=3,
//	BLUE=5
//}c;
//int main()
//{
//    c = BLUE;
//	printf("%d", c);
//}
#include <stdio.h>
int search(int arr[3][3], int row, int col, int n)
{
	int i = 0;
	int j = col - 1;
	while (i <= row && j >= 0)
	{
		if (n > arr[i][j])
		{
			i++;
		}
		else if (n < arr[i][j])
		{
			j--;
		}
		else
			return 1;
	}
	return 0;
}

int main()
{
	int a[][3] = { {1, 2, 3}, {4, 5, 6},{7, 8, 9} };
	if (search(a, 3, 3, 7))
		printf("找到了");S
	else
		printf("找不到");
	return 0;
}