#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int arr1[n];
    int arr2[m];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
    int arr[m + n];
    int j = 0;
    int k = 0;
    i = 0;
    while (k < m + n)
    {
        if (i == n || j == m)
        {
            if (i == n)
                arr[k++] = arr2[j++];
            else
                arr[k++] = arr1[i++];
        }
        else
        {
            if (arr1[i] > arr2[j])
                arr[k++] = arr2[j++];
            else
                arr[k++] = arr1[i++];
        }
    }
    for (i = 0; i < m + n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}