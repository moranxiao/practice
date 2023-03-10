#pragma warning(disable:4996)

#include <iostream>

namespace yyx
{
	int a = 10;
}
using namespace std;
using  yyx::a;

int main()
{
	cout << a << endl;
	return 0;
}