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

LNode* ListLocateElem(LNode* L, LDataType x)
{
	assert(L);

	LNode* iNode = L->next;

	while (iNode)
	{
		if (iNode->data == x)
			return iNode;
		iNode = iNode->next;
	}
	return NULL;
}

LNode* ListGetElem(LNode* L, int i)
{
	assert(L && i >= 0);
	int j = 0; //遍历链表
	LNode* iNode = L->next;

	while (iNode && j < i)
	{
		iNode = iNode->next;
		j++;
	}

	if (iNode == NULL)
		return NULL;
	else
		return iNode;
}

void ListInsert(LNode* L, int i, LDataType x)
{
	assert(L && i >= 0);

	int j = -1; //考虑头插的情况
	LNode* i_1Node = L;

	while (j < i - 1 && i_1Node)
	{
		i_1Node = i_1Node->next;
		j++;
	}

	assert(i_1Node != NULL); //i 超过了链表长度
	LNode* newNode = BuyListNode(x); 

	newNode->next = i_1Node->next;
	i_1Node->next = newNode;
}

//// 不带头结点的插入
//void ListInsert(LNode** L, int i, LDataType x)
//{
//	assert(i >= 0 && L != NULL);
//
//	// 头插：插入第 0 个位置
//	if (i == 0)
//	{
//		LNode* newNode = BuyListNode(x);
//		newNode->next = *L;
//		*L = newNode;
//		return;
//	}
//
//	// 找第 i - 1 个结点，也就是插入位置的前驱结点
//	LNode* i_1Node = *L;
//	int j = 0;
//
//	while (j < i - 1 && i_1Node != NULL)
//	{
//		i_1Node = i_1Node->next;
//		j++;
//	}
//
//	// 如果 i_1Node == NULL，说明 i 超过链表长度
//	assert(i_1Node != NULL);
//
//	// 插入到 i_1Node 后面
//	LNode* newNode = BuyListNode(x);
//	newNode->next = i_1Node->next;
//	i_1Node->next = newNode;
//}

// 带头结点的链表删除
// 删除下标为 i 的有效结点，i 从 0 开始
LDataType ListDelete(LNode* L, int i)
{
	assert(L && i >= 0);

	// j 记录 i_1Node 当前指向结点的下标
	// 头结点不是有效数据结点，因此将头结点看作下标 -1
	int j = -1;
	LNode* i_1Node = L;

	// 找到下标为 i 的结点的前一个结点
	while (j < i - 1 && i_1Node)
	{
		j++;
		i_1Node = i_1Node->next;
	}

	// 保证前驱结点存在，并且待删除结点存在
	assert(i_1Node && i_1Node->next);

	// iNode 指向待删除结点
	LNode* iNode = i_1Node->next;

	// 保存待删除结点的数据，方便删除后返回
	LDataType del = iNode->data;

	// 让前驱结点跳过待删除结点
	i_1Node->next = iNode->next;

	// 释放待删除结点
	free(iNode);

	return del;
}

////不带头结点的删除
//LDataType ListDelete(LNode** L, int i)
//{
//	assert(L && i >= 0);
//
//	int j = 0;
//	LNode* i_1Node = *L;
//
//	//头删
//	if (i == 0)
//	{
//		LNode* iNode = *L;
//		*L = (*L)->next;
//		LDataType del = iNode->data;
//		free(iNode);
//		iNode = NULL;
//		return del;
//	}
//
//	while (j < i - 1 && i_1Node)
//	{
//		i_1Node = i_1Node->next;
//		j++;
//	}
//
//	assert(i_1Node && i_1Node->next);
//
//	LNode* iNode = i_1Node->next;
//	LDataType del = iNode->data;
//	i_1Node->next = iNode->next;
//	free(iNode);
//	iNode = NULL;
//	return del;
//}



