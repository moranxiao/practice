#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void merg(char* arr, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;
    char* ptr = (char*)malloc(right - left + 1);
    if (ptr == NULL)
        return;
    while (i <= mid && j <= right)
    {
        ptr[k] = arr[i] > arr[j] ? arr[j++] : arr[i++];
        k++;
    }
    while (i <= mid)
        ptr[k++] = arr[i++];
    while (j <= right)
        ptr[k++] = arr[j++];
    for (k = 0, i = left; i <= right; k++, i++)
    {
        arr[i] = ptr[k];
    }
    free(ptr);
    ptr = NULL;
}
void merg_sort(char* arr, int left, int right)
{
    if (arr == NULL)
        return;
    if (left == right)
        return;
    int mid = ((right - left) >> 1) + left;
    merg_sort(arr, left, mid);
    merg_sort(arr, mid + 1, right);
    merg(arr, left, mid, right);
}
int main()
{
    char arr[1001] = { 0 };
    scanf("%s", arr);
    merg_sort(arr, 0, strlen(arr) - 1);
    printf("%s", arr);
    return 0;
}