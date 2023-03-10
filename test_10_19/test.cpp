#include <iostream>

using namespace std;

int addAB(int A, int B) {
    int add = 0;
    int next = 0;
    for (int i = 0; i < 32; i++)
    {
        if (((A >> i) & 1 + (B >> i) & 1 + next) > 1)
        {
            add += (((A >> i) & 1 + (B >> i) & 1 + next) % 2 << i);
            next = 1;
        }
        else
        {
            add += (((A >> i) & 1 + (B >> i) & 1 + next) << i);
            next = 0;
        }
    }
    return add;
}
int main()
{
    addAB(1, 2);
	return 0;
}