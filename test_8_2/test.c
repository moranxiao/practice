#pragma warning(disable:4996)

#include "list.h"

void test()
{
	LTNode* p = ListCreate();
	ListPushBack(p, 1);
	ListPushBack(p, 2);
	ListPushBack(p, 3);
	ListPushBack(p, 4);
	ListPushBack(p, 5);
	//ListPushFront(p, 1);
	//ListPushFront(p, 2);
	//ListPushFront(p, 3);
	//ListPushFront(p, 4);
	//ListPushFront(p, 5);
	ListPrint(p);
	printf("\n");
	//ListInsert(ListFind(p, 9), 10);
	//ListPopBack(p);
	//ListPopBack(p);
	//ListPopBack(p);
	//ListPopBack(p);
	//ListPopBack(p);
	//ListPopBack(p);
	//ListPrint(p);
	//ListPopFront(p);
	//ListPopFront(p);
	//ListPopFront(p);
	//ListPopFront(p);
	//ListPopFront(p);
	//ListPopFront(p);

	ListPrint(p);
}
int main()
{
	test();
	return 0;
}