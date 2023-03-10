#pragma once 

namespace yyx {
	template<class T>
	class auto_ptr {
	public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}
		~auto_ptr()
		{
			delete _ptr;
		}
		auto_ptr(auto_ptr<T>& p)
			:_ptr(p._ptr)
		{
			p._ptr = nullptr;
		}
		auto_ptr<T>& operator=(auto_ptr<T>& p)
		{
			if (_ptr != p._ptr)
			{
				delete _ptr;
				_ptr = p._ptr;
				p._ptr = nullptr;
			}
			return *this;
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	void test1()
	{
		auto p = new int(1);
		auto_ptr<int> ap = p;
		auto_ptr<int> ap1 = ap;
		*ap1 = 3;
		*ap = 1;
	}
}