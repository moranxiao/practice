#pragma once 

namespace yyx {
	template<class T,class Container = deque<T>>
	class stack {
	public:
		stack()
			:_con()
		{}
		bool empty()
		{
			return _con.empty();
		}
		size_t size()
		{
			return _con.size();
		}
		T& top()
		{
			return _con.back();
		}
		void pop()
		{
			_con.pop_back();
		}
		void push(const T& val)
		{
			_con.push_back(val);
		}
	private:
		Container _con;
	};
}