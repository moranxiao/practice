#pragma once

namespace yyx {
	template<class T>
	class shared_ptr {
	public:
		shared_ptr(T* ptr = nullptr)
			:_ptr(ptr),
			 _pcount(new int(1))
		{}
		~shared_ptr()
		{
			if (-- * _pcount)
			{
				delete _ptr;
				delete _pcount;
			}
		}
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		shared_ptr(shared_ptr<T>& p)
			:_ptr(p._ptr),
			_pcount(p._pcount)
		{
			++* _pcount;
		}
		shared_ptr<T>& operator=(shared_ptr<T>& p)
		{
			if (_ptr != p._ptr)
			{
				if (-- * _pcount)
				{
					delete _ptr;
					delete _pcount;
				}
				_ptr = p._ptr;
				_pcount = p._pcount;
				++* _pcount;
			}
			return *this;
		}
		T* get()
		{
			return _ptr;
		}
	private:
		T* _ptr;
		int* _pcount;
	};
	
	template<class T>
	class weak_ptr {
		weak_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}
		weak_ptr<T>& operator=(const shared_ptr<T>& p)
		{
			_ptr = p.get();
			return *this;
		}
		weak_ptr<T>& operator=(const weak_ptr<T>& p)
		{
			_ptr = p._ptr;
			return *this;
		}
		weak_ptr(const shared_ptr<T>& p)
			:_ptr(p.get())
		{}
	private:
		T* _ptr;
	};
}