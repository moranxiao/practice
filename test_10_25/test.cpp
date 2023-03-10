#include <iostream>
using namespace std;

class A
{
	
};

class B : public A
{
	
};

int main()
{
	A* a = new B;
	delete a;
	return 0;
}