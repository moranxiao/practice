#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int cmp(void* e1,void* e2)
{
	return *((int*)e1) - *((int*)e2);
}
int main()
{
	FILE* f = fopen("data.txt", "r");
	if (f == NULL)
	{
		perror("fopen fail");
		exit(-1);
	}
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			fscanf(f, "%d\n", arr + j);
		}
		qsort(arr, 10, sizeof(int), cmp);
		char name[10] = { 0 };
		sprintf(name, "%d", i + 1);
		FILE* fin = fopen(name, "w");
		for (int j = 0; j < 10; j++)
		{
			fprintf(fin, "%d\n", arr[j]);
		}
	}
	return 0;
}