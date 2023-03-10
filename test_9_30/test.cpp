#include <iostream>
#include <string>

using namespace std;

//template <typename T>
//T Add(T a, T b)
//{
//	return a + b;
//}
//
//int main()
//{
//	//cout << Add(1, 2) << endl;
//	//cout << Add('c', (char)1) << endl;
//	//cout << Add(1.1, 2.2) << endl;
//
//	//string s1("abcd");
//	string s("hello world");
//	//string::iterator it = s.begin();
//	//while (it != s.end())
//	//{
//	//	cout << *it << endl;
//	//	it++;
//	//}
//	//for (auto ch : s)
//	//{
//	//	cout << ch << endl;
//	//}
//	string::reverse_iterator rit = s.rbegin();
//	while(rit != s.rend())
//	{
//		
//	}
//	return 0;
//}
int  main(int argc, char* argv[])
{
	string a = "hello world";
	string b = a;
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	string c = b;
	c = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	a = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	return 0;
}