#include  <iostream>

using namespace std;

namespace yyx {
	class string {
	public:
		string& operator=(const string& str)
		{
			string tmp(str);
			
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}