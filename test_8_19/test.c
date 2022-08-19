#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* arr = (int*)malloc(sizeof(int) * numsSize);
    int min = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (abs(nums[i]) < abs(nums[min]))
        {
            min = i;
        }
    }
    int left = min;
    int right = min;
    int k = 0;
    while (left >= 0 && right < numsSize)
    {
        if (abs(nums[left]) < abs(nums[right]))
        {
            arr[k++] = nums[left] * nums[left];
            left--;
        }
        else
        {
            arr[k++] = nums[right] * nums[right];
            right++;
        }
    }
    while (left >= 0)
    {
        arr[k++] = nums[left] * nums[left];
        left--;
    }
    while (right < numsSize)
    {
        arr[k++] = nums[right] * nums[right];
        right++;
    }
    return arr;
}
int main()
{
    int arr[] = { -4,-1,0,3,10 };
    int i = 0;
    sortedSquares(arr, 5, &i);
    return 0;
}