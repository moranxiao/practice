#pragma once

namespace yyx {
	template<class T>
	class unique_ptr {
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}
		unique_ptr(unique_ptr<T>& ptr) = delete;
		~unique_ptr()
		{
			delete _ptr;
		}
		T& operator=(unique_ptr<T>& ptr) = delete;
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
	void test2()
	{
		
	}
}