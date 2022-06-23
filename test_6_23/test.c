#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n;
    int i, j;
    scanf("%d %d", &n, &m);
    int** arr = (int**)malloc(sizeof(int*) * n);
    if (arr == NULL)
        return;
    for (i = 0; i < n; i++)
    {
        arr[i] = (int*)malloc(sizeof(int) * m);
        if (arr[i] == NULL)
            return;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            arr[i][j] = 1;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}