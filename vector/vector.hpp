#pragma once 

namespace yyx {
	template <class T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{}
		template <class Iterator>
		vector(Iterator begin, Iterator end)
			: _start(nullptr),
			 _finish(nullptr),
			_end_of_storage(nullptr)
		{
			while (begin != end)
			{
				push_back(*begin);
				begin++;
			}
		}
		vector(size_t n, const T& val = T())
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		vector(int n, const T& val = T())
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);

		}
		vector(const vector<T>& v)
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}
		vector<T>& operator=(vector<T> tmp)
		{
			swap(tmp);
			return *this;
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}
		size_t capacity()
		{
			return _end_of_storage - _start;
		}
		size_t size()
		{
			return _finish - _start;
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}
		void reserve(size_t n)
		{
			if (capacity() < n)
			{
				iterator ptr = new T[n];
				size_t sz = size();
				for (size_t i = 0; i < sz; i++)
				{
					ptr[i] = _start[i];
				}
				delete[] _start;
				_start = ptr;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}
		void push_back(const T& val)
		{
			if (size() == capacity())
			{
				size_t newcap = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcap);
			}
			*_finish++ = val;
		}
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos)const
		{
			assert(pos < size());
			return _start[pos];
		}
		iterator insert(iterator pos, const T& val)
		{
			assert(pos <= size());
			if (size() == capacity())
			{
				size_t newcap = capacity() == 0 ? 4 : 2 * capacity();
				reserve(newcap);
			}
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
	void vector_test1()
	{
		int arr[] = { 1,2,3,4,5 };
		const vector<int> v(arr,arr+5);
		for (auto e : v)
		{
			cout << e << ' ';
		}
		cout << endl;
	}
	void vector_test2()
	{
		vector<int> v(10, 1);
		for (int i = 0; i < v. size(); i++)
		{
			cout << v[i];
		}
		
	}
	void vector_test3()
	{
		vector<int> v1(5, 2);
		vector<int> v2(v1);
		vector<int> v3;
		v3 = v1;
	}
	void vector_test4()
	{
		vector<vector<int>> vv;
		
	}
	void vector_test5()
	{
		
	}
}