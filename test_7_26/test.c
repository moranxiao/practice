#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
void swap(char* arr, int a, int b)
{
    if (a == b)
        return;
    arr[a] = arr[a] ^ arr[b];
    arr[b] = arr[a] ^ arr[b];
    arr[a] = arr[a] ^ arr[b];
}
void my_qsort(char* arr, int left, int right)
{
    if (left = right - 1)
    {
        return;
    }
    int i = left;
    int L = left-1;
    int R = right;
    while (i <= R)
    {
        if (arr[i] > arr[right])
        {
            R--;
            swap(arr, i, R);
        }
        else if (arr[i] < arr[right])
        {
            L++;
            swap(arr, i, L);
            i++;
        }
        else
            i++;
    }
    swap(arr, R, right);
    my_qsort(arr, left, L);
    my_qsort(arr, R, right);
}
int main()
{
    char arr[1001] = { 0 };
    scanf("%s", arr);
    my_qsort(arr, 0, strlen(arr) - 1);
    printf("%s", arr);
    return 0;
}