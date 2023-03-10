#include <stdio.h>
#include <stdlib.h>
#define DataType int

typedef struct ListNode
{
	DataType _data;
	struct ListNode* _next;
}Node;
typedef struct List
{
	Node* _head;
}List;

Node* CreatNode(DataType data)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->_data = data;
	newnode->_next = NULL;
	return newnode;
}
List* CreatList(DataType* data,size_t sz) 
{
	List* lt = (List*)malloc(sizeof(List));
	if (lt == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	lt->_head = NULL;
	Node* prev = CreatNode(data[0]);
	lt->_head = prev;
	for (size_t i = 1; i < sz; i++)
	{
		Node* newnode = CreatNode(data[i]);
		prev->_next = newnode;
		prev = prev->_next;
	}
	return lt;
}

List* EraseNode(List* lt,Node* node)
{
	if (node == lt->_head)
		return NULL;
	Node* prev = lt->_head;
	Node* cur = lt->_head->_next;
	while (cur)
	{
		if (cur == node)
		{
			prev->_next = cur->_next;
			free(cur);
		}
		prev = cur;
		cur = cur->_next;
	}
	return lt;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6 };
	List* lt = CreatList(arr, 6);
	return 0;
}