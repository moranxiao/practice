#pragma warning(disable:4996)
#include <stdio.h>
void Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void BubbleSort(int a[], int sz)
{
    for (int i = 0; i < sz - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < sz - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                Swap(a + j, a + j + 1);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

void SelectSort(int arr[], int sz)
{
    int begin = 0;
    int end = sz - 1;
    while (begin < end)
    {
        int max = begin;
        int min = begin;
        for (int i = begin + 1; i <= end; i++)
        {
            if (arr[i] > arr[max])
            {
                max = i;
            }
            else if (arr[i] < arr[min])
            {
                min = i;
            }
        }
        Swap(arr + min, arr + begin);
        if (max == begin)
        {
            Swap(arr + min, arr + end);
        }
        else
        {
            Swap(arr + max, arr + end);
        }
        end--;
        begin++;
    }
}
void InsertSort(int arr[], int sz)
{
    for (int i = 1; i < sz; i++)
    {
        int tmp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > tmp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}

int main()
{
    int arr[] = { 99 ,28 ,72, 12,83,67,6,21,10 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    InsertSort(arr, sz);
    return 0;
}
