#include <iostream>
#include <string>
using namespace std;
//namespace yyx {
//	class string {
//	public:
//		string(const char* str)
//		{
//			_str = new char[strlen(str)+1];
//			strcpy(_str, str);
//		}
//	private:
//		char* _str;
//	};
//
//}
int main()
{
	string s("hello");
	s.insert(2,1, '\0');
	s += "world";
	string s1 = s;
	cout << s << endl << s1 << endl;
	return 0;
}