#pragma once
	
namespace yyx {
	class string {
		typedef char* iterator;
		typedef const char* const_iterator;
	public:

		string(const char* str = "")
			:_str(nullptr),
			_size(0),
			_capacity(0)
		{
			_capacity = _size = strlen(str);
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		void swap(string& tmp)
		{
			::swap(_str, tmp._str);
			::swap(_size, tmp._size);
			::swap(_capacity, tmp._capacity);
		}
		string(const string& s)
			:_str(nullptr),
			_capacity(0),
			_size(0)
		{
			string tmp(s._str);
			swap(tmp);
		}
		string& operator=(string tmp)
		{
			swap(tmp);
			return *this;
		}
		~string()
		{
			delete[] _str;
			_capacity = 0;
			_size = 0;
		}
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin()const
		{
			return _str;
		}
		const_iterator end()const
		{
			return _str + _size;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return *(_str + pos);
		}
		void reserve(size_t sz)
		{
			if (sz > _capacity)
			{
				_capacity = sz;
				char* ptr = new char[sz + 1];
				strncpy(ptr, _str,_size);
				ptr[_capacity] = '\0';
				delete[] _str;
				_str = ptr;
			}
		}
		string& operator+=(const char ch)
		{
			insert(_size, ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			insert(_size, str);
			return *this;
		}
		void resize(size_t sz, char ch = '\0')
		{
			
			if (sz >= _size)
			{
				reserve(sz);
				while (_size != sz)
				{
					_str[_size++] = ch;
				}
			}
			else
			{
				_size = sz;
				_str[_size] = '\0';
			}
		}
		size_t size()
		{
			return _size;
		}
		const char* c_str()const 
		{
			return _str;
		}
		string& insert(size_t pos,const char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				size_t newsz = _capacity == 0 ? 4 : 2 * _capacity;
				reserve(newsz);
			}
			size_t end = _size;
			for (; end > pos; end--)
			{
				_str[end] = _str[end - 1];
			}
			_size++;
			_str[pos] = ch;
			return *this;
		}
		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (len + _size > _capacity)
			{
				reserve(len + _size);
			}
			for (size_t i = _size + len - 1; i > pos; i--)
			{
				_str[i] = _str[i - len];
			}
			strncpy(_str + pos, str, len);
			_size = len + _size;
			return *this;
		}
		string& erase(size_t pos, size_t n = npos)
		{
			assert(pos < _size);
			if (n + pos > _size)
			{
				resize(pos);
			}
			else
			{
				for (int i = pos+n; i <= _size; i++)
				{
					_str[i - n] = _str[i];
				}
				_size -= n;
			}
			return *this;
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		size_t find(char ch, size_t pos = 0)const
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; i++)
			{
				if (ch == _str[i])
				{
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* ch, size_t pos = 0)const
		{
			assert(ch);
			assert(pos < _size);
			char* ptr = strstr(_str+pos, ch);
			if (ptr == nullptr)
				return npos;
			else
				return ptr - _str;
		}
		string substr(size_t pos = 0, size_t len = npos) const
		{
			assert(pos < _size);
			if (len == npos || len + pos >= _size )
				return _str+pos;
			string ret;
			ret.reserve(len);
			for (size_t i = 0; i < len; i++)
			{
 				ret += _str[i + pos];
			}
			return ret;
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	public:
		const static size_t npos = -1;
	};
	ostream& operator<<(ostream& out,string& s)
	{
		for (int i = 0; i < s.size(); i++)
		{
			out << s[i];
		}
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char ch;
		in.get(ch);
		int sz = 0;
		char buff[32];
		while (ch != '\n' && ch != ' ')
		{
			buff[sz++] = ch;
			if (sz + 1 == 32)
			{
				buff[sz] = '\0';
				s += buff;
				sz = 0;
			}
			in.get(ch);
		}
		buff[sz] = '\0';
		s += buff;
		return in;
	}
	void string_test1()
	{
		string s0;
		string s2("hello");
		string s3(s2);
		s0 = s3;
	}
	void string_test2()
	{
		string s1 = "hello world";
		for (auto e : s1)
		{
			cout << e << ' ';
		}
		cout << endl;
		const string s2 = "hello world";

		for (auto& e : s2)
		{
			cout << e << ' ';
		}

	}
	void string_test3()
	{
		string s1;
		s1 += "hello wolrd";
		for (auto e : s1)
		{
			cout << e;
		}
		cout << endl;
		s1.insert(0, "hello");
		//for (int i = 0; i < s1.size(); i++)
		//{
		//	s1[i]++;
		//}


		for (auto e : s1)
		{
			cout << e;
		}
		cout << endl;
	}
	void string_test4()
	{
		string s1, s2;
		cin >> s1 >> s2;
		cout << s1 << s2;
	}
	void DealUrl(const string& url)
	{
		size_t pos1 = url.find("://");
		if (pos1 == string::npos)
		{
			cout << "非法url" << endl;
			return;
		}
		// 休息到16:08继续

		string protocol = url.substr(0, pos1);
		cout << protocol << endl;

		size_t pos2 = url.find('/', pos1 + 3);
		if (pos2 == string::npos)
		{
			cout << "非法url" << endl;
			return;
		}
		string domain = url.substr(pos1 + 3, pos2 - pos1 - 3);
		cout << domain << endl;

		string uri = url.substr(pos2 + 1);
		cout << uri << endl << endl;
	}

	void string_test10()
	{
		string url1 = "https://cplusplus.com/reference/string/string/";
		string url2 = "https://image.baidu.com/search/detail?ct=503316480&z=0&ipn=d&word=ascall&step_word=&hs=0&pn=0&spn=0&di=7108135681917976577&pi=0&rn=1&tn=baiduimagedetail&is=0%2C0&istype=0&ie=utf-8&oe=utf-8&in=&cl=2&lm=-1&st=undefined&cs=2613959014%2C543572025&os=2740573600%2C1059518451&simid=2613959014%2C543572025&adpicid=0&lpn=0&ln=179&fr=&fmq=1660115697093_R&fm=&ic=undefined&s=undefined&hd=undefined&latest=undefined&copyright=undefined&se=&sme=&tab=0&width=undefined&height=undefined&face=undefined&ist=&jit=&cg=&bdtype=0&oriquery=&objurl=https%3A%2F%2Fgimg2.baidu.com%2Fimage_search%2Fsrc%3Dhttp%3A%2F%2Fimg.php.cn%2Fupload%2Fimage%2F147%2F157%2F796%2F1593765739620093.png%26refer%3Dhttp%3A%2F%2Fimg.php.cn%26app%3D2002%26size%3Df9999%2C10000%26q%3Da80%26n%3D0%26g%3D0n%26fmt%3Dauto%3Fsec%3D1662707704%26t%3Da68cb238bbb3f99d0554098c785d526e&fromurl=ippr_z2C%24qAzdH3FAzdH3Fooo_z%26e3Brir_z%26e3BvgAzdH3FuwqAzdH3F9c9amd_z%26e3Bip4s&gsm=1&rpstart=0&rpnum=0&islist=&querylist=&nojc=undefined&dyTabStr=MCwzLDIsNCw2LDEsNSw3LDgsOQ%3D%3D";
		string url3 = "ftp://ftp.cs.umd.edu/pub/skipLists/skiplists.pdf";

		DealUrl(url1);
		DealUrl(url2);
		DealUrl(url3);
	}
}

