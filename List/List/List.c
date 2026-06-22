#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

//单独申请结点的函数
LNode* BuyListNode(int data)
{
	LNode* newNode = (LNode*)malloc(sizeof(LNode));

	if (newNode == NULL)
	{
		perror("newNode");
		return NULL;
	}

	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

LNode* ListInit()
{
	LNode* head = BuyListNode(-1);
	return head;
}

void ListPrint(LNode* L)
{
	assert(L); //带头结点，加上assert,不带头结点，不加assert

	LNode* cur = L->next;

	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");

}

int ListSize(LNode* L)
{
	assert(L);

	LNode* cur = L->next; //头结点不是有效元素

	int cnt = 0;
	while (cur)
	{
		cnt++;
		cur = cur->next;
	}
	return cnt;
}

