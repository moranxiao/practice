#include <iostream>
using namespace std;

//class A
//{
//public:
//	virtual void func()
//	{
//		cout << "A:func" << endl;
//	}
//	int _a;
//};
//
//class B : public A
//{
//public:
//	virtual void func()
//	{
//		cout << "B:func" << endl;
//	}
//};

class A
{
public:
	void func()
	{
		cout << "A:func" << endl;
	}
};

class B : public A
{
public:
	void func(int i)
	{
		cout << "B:func" << endl;
	}
};

int main()
{
	B b;
	A* ptr = &b;
	ptr->func();
	return 0;
}