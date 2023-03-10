//#include <iostream>
//using namespace std;
//
//class A {
//public:
//	virtual void func()
//	{
//		cout << "A::func" << endl;
//	}
//};
//class B : public A
//{
//public:
//	virtual	void func()
//	{
//		cout << "B::func" << endl;
//	}
//};
//int main()
//{
//	B b;
//	A a = b;
//	a.func();
//	return 0;
//}

//int main()
//{
//	return 0;
//}

class A {
public:
	A() = default;
	const static int a;
};
int main()
{
	return 0;
}