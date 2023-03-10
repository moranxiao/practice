#include <iostream>
#include <memory>
#include <map>
#include <string>

#include "shared_ptr.hpp"
#include "auto_ptr.hpp"
#include "unique_ptr.hpp"
using namespace std;

void test()
{
	int* p = new int(0);
	auto_ptr<int> ap1(p);
	auto_ptr<int> ap2(p);
	ap1 = ap2;
	*ap1 = 1;
}

int main()
{
	//yyx::test2();
	test();
	return 0;
}