#include <iostream>
#include <functional>

using namespace std;

int main()
{
	auto FuncAdd = [](int a, int b){return a + b; };
	
	cout << func(1, 2);
	return 0;
}