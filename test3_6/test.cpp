#include <iostream>

namespace yyx {
	int a = 0;
	int b = 1;
	int c = 2;
}
using yyx::a;
int main()
{
	std::cout << a << std::endl;
	return 0;
}