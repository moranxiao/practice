#include <iostream>

using namespace std;

//class A
//{
//private:
//	~A()
//	{}
//};
//class B
//{
//public:
//	~B() = delete;
//};
//class C
//{
//public:
//	static C Create()
//	{
//
//	}
//private:
//	C()
//	{}
//};

	class MemoryPool
	{
	public:
		MemoryPool* getInstance()
		{
			return	_Instance;
		}
	private:
		MemoryPool()
		{}
		MemoryPool(MemoryPool& p)
		{}

		static MemoryPool* _Instance;
	};

	MemoryPool* MemoryPool::_Instance = new MemoryPool;
int main()
{
	//A* pa = new A;
	//B* pb = new B;
	return 0;
}