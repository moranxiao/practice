#pragma warning(disable:4996)
#include "seqlist.h"
void test(SL* s)
{
	//SeqListPushBack(s, 10);
	//SeqListPushBack(s, 20);
	//SeqListPushBack(s, 30);
	//SeqListPushBack(s, 40);
	//SeqListPushBack(s, 50);
	//SeqListPrint(s);
	
	SeqListPushFront(s, 10);
	SeqListPushFront(s, 20);
	SeqListPushFront(s, 30);
	SeqListPushFront(s, 40);
	SeqListPushFront(s, 50);
	SeqListPrint(s);
	printf("\n");
	//SeqListPopFront(s);
	//SeqListPopFront(s);
	//SeqListPopFront(s);
	//SeqListPopFront(s);
	//SeqListPopFront(s);
	//SeqListPopFront(s);
	//SeqListPopBack(s);
	//SeqListPopBack(s);
	//SeqListPopBack(s);
	//SeqListPopBack(s);
	//SeqListPopBack(s);
	//SeqListPopBack(s);
	//SeqListPrint(s);
	int x = 0;
	scanf("%d", &x);
	SeqListErase(s, SeqListFind(s, x));
	SeqListPrint(s);
}

int main()
{
	SL s;
	SeqListInit(&s);
	test(&s);
	//SeqListDestroy(&s);
	return 0;
}