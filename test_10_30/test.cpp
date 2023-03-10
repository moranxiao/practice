#include "AVLTree.h"

class A {
public:

	void test(float a) { cout << "1"; }
};
class B :public A {
public:

	void test(int b) { cout << "2"; }
};
int main()
{
	A* a = new A;
	B* b = new B;
	a = b;
	a->test(1);
	return 0;
}
