#include "string.hpp"

//class AA {
//public:
//	AA(int a1 = 0,int a2 = 0)
//		:_a1(a1)
//		,_a2(a2)
//	{
//		;
//	}
//	~AA()
//	{
//		;
//	}
//	int _a1;
//	int _a2;
//};
//int main()
//{
//	AA* a = (AA*)malloc(sizeof(AA) * 3);
//	for (int i = 0; i < 3; i++)
//	{
//		new(a+i)AA;
//	}
//	return 0;
//}
using namespace std;
int main()
{
	string s("hello world");
	const char* s1 = s.c_str();

	return 0;
}