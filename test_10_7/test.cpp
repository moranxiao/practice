#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        for (auto& e : s)
        {
            if (e >= 'A' && e <= 'Z')
            {
                e += 32;
            }
        }
        int begin = 0, end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && (!isalpha(s[begin])))
                begin++;
            while (begin < end && (!isalpha(s[end])))
                end--;
            if (s[begin] != s[end])
                return false;
            begin++;
            end--;
        }
        return true;
    }
};
int main()
{
	//string s("hello world");
	//cout << s.capacity() << endl;
	//s.reserve(5);
	//cout << s.capacity() << endl;
    Solution().isPalindrome("OP");
    return 0;
}