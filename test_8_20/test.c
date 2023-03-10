#pragma warning(disable:4996)
void reverse(int* left, int* right)
{
    while (left < right)
    {
        int tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}
void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;

    reverse(nums, nums + numsSize - 1 - k);
    reverse(nums + numsSize - k, nums + numsSize - 1);
    reverse(nums, nums + numsSize - 1);
}