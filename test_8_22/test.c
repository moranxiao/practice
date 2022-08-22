#pragma warning(disable:4996)
void reverse(char* left, char* right)
{
    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}
char* reverseWords(char* s) {
    char* prev = s;
    char* cur = s;
    while (*cur)
    {
        prev = cur;
        while (*cur && *cur != ' ')
        {
            cur++;
        }
        reverse(prev, cur - 1);
        if (*cur == ' ')
            cur++;
    }
    return s;
}