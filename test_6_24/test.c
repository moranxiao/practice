#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n = 0;
    int i, j;
    scanf("%d", &n);
    int** arr = (int**)calloc(n, sizeof(int**));
    if (arr == NULL)
        return 0;
    for (i = 0; i < n; i++)
    {
        arr[i] = (int*)calloc(n, sizeof(int*));
        if (arr[i] == NULL)
            return 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
            if (j < i)
            {
                if (arr[i][j] != 0)
                {
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }
    printf("YES\n");
    return 0;
}