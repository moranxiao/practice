#include "linklist.h"

void test()
{
	SListNode* p = NULL;
	SListPushFront(&p, 1);
	SListPushFront(&p, 2);
	SListPushFront(&p, 3);
	SListPushFront(&p, 4);
	SListPushFront(&p, 5);
	SListPushBack(&p, 6);
	SListPrint(p);
	//SListPopFront(&p);
	//SListPopFront(&p);
	//SListPopFront(&p);
	//SListPopFront(&p);
	//SListPopFront(&p);
	//SListPopFront(&p);
	//SListPopFront(&p);
	//SListInsert(&p, SListFind(p, 2), 20);
	//SListInsert(&p, SListFind(p, 3), 30);
	//SListInsert(&p, SListFind(p, 4), 40);

	//SListInsert(&p,SListFind(p, 6),60);
	//SListPrint(p);
	//SListEraseAfter(SListFind(p, 60));
	////SListEraseAfter(SListFind(p, 30));

	//SListEraseAfter(SListFind(p, 2));

	//SListErase(&p, SListFind(p, 1));
	//SListErase(&p,SListFind(p, 2));
	SListDestroy(&p);
	SListPrint(p);

}

int main()
{
	test();
	return 0;
}