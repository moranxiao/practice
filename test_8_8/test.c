#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void AdjustDown(int* a, int parent, int sz)
{
	int son = parent * 2 + 1;
	if (son + 1 < sz && a[son] > a[son+1])
	{
		son++;
	}
	while (son < sz)
	{
		if (son + 1 < sz && a[son] > a[son + 1])
		{
			son++;
		}
		if (a[parent] > a[son])
		{
			Swap(&a[parent], &a[son]);
			parent = son;
			son = son * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//
//void HeapSort(int* a, int sz)
//{
//	for (int i = (sz - 2) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, i, sz);
//	}
//	int j = sz - 1;
//	while (j)
//	{
//		Swap(&a[0], &a[j]);
//		AdjustDown(a, 0, j);
//		j--;
//	}
//}
void CreateFile(const char* FileName, int n)
{
	FILE* file = fopen(FileName, "w");
	assert(file);
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		fprintf(file, "%d ", rand() % 10000);
	}
	fclose(file);
}

void TopK(const char* file,int k)
{
	int* arr = (int*)malloc(sizeof(int) * k);
	if (arr == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	FILE* fout = fopen(file, "r");
	assert(fout);
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &arr[i]);
	}
	for (int i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDown(arr, i, k);
	}
	int n = 0;
	while (fscanf(fout, "%d", &n) != EOF)
	{
		if (n > arr[0])
		{
			Swap(&n, &arr[0]);
			AdjustDown(arr, 0, k);
		}
	}
	fclose(fout);
	for (int i = 0; i < k; i++)
	{
		printf("%d ", arr[i]);
	}
	free(arr);
}

int main()
{
//	int a[] = { 9,8,7,6,5,4,3,2,1,0 };
//	HeapSort(a, 10);
	const char* filename = "data.txt";
	int N = 10000;
	//CreateFile(filename,N);
	TopK(filename, 10);
	return 0;
}