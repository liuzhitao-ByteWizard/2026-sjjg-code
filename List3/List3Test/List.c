#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

// 创建新结点
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
	assert(L); //带头结点，用assert，没有头结点，也用assert

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

	LNode* cur = L->next; //头结点不存有效元素

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
	int j = 0; //计数器变量
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

	int j = -1; //把头结点看作下标
	LNode* i_1Node = L;

	while (j < i - 1 && i_1Node)
	{
		i_1Node = i_1Node->next;
		j++;
	}

	assert(i_1Node != NULL); //i 超过链表长度范围
	LNode* newNode = BuyListNode(x);

	newNode->next = i_1Node->next;
	i_1Node->next = newNode;
}

//// 不带头结点的插入
//void ListInsert(LNode** L, int i, LDataType x)
//{
//	assert(i >= 0 && L != NULL);
//
//	// 头插：处理 0 号位置
//	if (i == 0)
//	{
//		LNode* newNode = BuyListNode(x);
//		newNode->next = *L;
//		*L = newNode;
//		return;
//	}
//
//	// 找到 i - 1 号结点，也就是插入位置的前驱结点
//	LNode* i_1Node = *L;
//	int j = 0;
//
//	while (j < i - 1 && i_1Node != NULL)
//	{
//		i_1Node = i_1Node->next;
//		j++;
//	}
//
//	// 如果 i_1Node == NULL，说明 i 超过了链表长度
//	assert(i_1Node != NULL);
//
//	// 插入到 i_1Node 后面
//	LNode* newNode = BuyListNode(x);
//	newNode->next = i_1Node->next;
//	i_1Node->next = newNode;
//}

// 带头结点链表的删除
// 删除下标为 i 的有效结点，i 从 0 开始
LDataType ListDelete(LNode* L, int i)
{
	assert(L && i >= 0);

	// j 记录 i_1Node 当前指向结点的下标
	// 头结点不存有效数据结点，因此将头结点看作下标 -1
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

	// 保存待删除结点的数据，删除后返回
	LDataType del = iNode->data;

	// 让前驱结点跳过待删除结点
	i_1Node->next = iNode->next;

	// 释放待删除结点
	free(iNode);

	return del;
}

// 判断链表是否为空：空返回 true，非空返回 false
bool ListEmpty(LNode* L)
{
	assert(L);

	return L->next == NULL;
}

// 头插：在头结点后插入新结点（即下标 0 位置）
void ListPushFront(LNode* L, LDataType x)
{
	assert(L);

	LNode* newNode = BuyListNode(x);
	newNode->next = L->next;
	L->next = newNode;
}

// 尾插：在链表末尾插入新结点
void ListPushBack(LNode* L, LDataType x)
{
	assert(L);

	LNode* tail = L;
	while (tail->next)
	{
		tail = tail->next;
	}

	LNode* newNode = BuyListNode(x);
	tail->next = newNode;
}

// 头删：删除首元结点，返回被删结点的数据
LDataType ListPopFront(LNode* L)
{
	assert(L && L->next);

	LNode* del = L->next;
	LDataType ret = del->data;

	L->next = del->next;
	free(del);

	return ret;
}

// 尾删：删除最后一个有效结点，返回被删结点的数据
LDataType ListPopBack(LNode* L)
{
	assert(L && L->next);

	LNode* prev = L;
	while (prev->next->next)
	{
		prev = prev->next;
	}

	LNode* del = prev->next;
	LDataType ret = del->data;

	prev->next = NULL;
	free(del);

	return ret;
}
// 销毁链表：释放所有结点（包括头结点）
void ListDestroy(LNode* L)
{
	assert(L);

	LNode* cur = L;
	while (cur)
	{
		LNode* next = cur->next;
		free(cur);
		cur = next;
	}
}
