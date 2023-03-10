#pragma warning(disable:4996)
#include <iostream>
using namespace std;
void TestFor()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto& e : array)
		e *= 2;
	for (auto e : array)
		cout << e << " ";
	return;
}
int main()
{
	TestFor();
	return 0;
}