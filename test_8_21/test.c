#pragma warning(disable:4996)
void Swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void moveZeroes(int* nums, int numsSize) {
    int prev = 0;
    int cur = 0;
    while (cur < numsSize)
    {
        while (prev < numsSize && nums[prev] != 0)
        {
            prev++;
        }
        if (prev == numsSize)
            break;
        cur = prev;
        while (cur < numsSize && nums[cur] == 0)
        {
            cur++;
        }
        if (cur == numsSize)
            break;
        Swap(nums + cur, nums + prev);
        prev = cur;
    }
}