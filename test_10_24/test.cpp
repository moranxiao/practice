#include <iostream>
using namespace std;

class A
{
public:
	A(int a)
		:_a(a)
	{
	}
	A& operator=(const A& a)
	{
		_a = a._a;
		return *this;
	}
protected:
	int _a;
};
class B :public A
{
public:
	B(int b,int a)
		:_b(b),
		A(a)
	{}
	B& operator=(const B& b)
	{
		_b = b._b;
		A::operator=(b);
		return *this;
	}
protected:
	int _b;
};
int main()
{
	B b1(1,2);
	B b2(2, 1);
	b1 = b2;
	return 0;
}