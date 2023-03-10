#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str("hello");
	str += '\0';
	str += "world";
	cout << str << endl;
	string copy(str);
	cout << copy << endl;
	return 0;
}