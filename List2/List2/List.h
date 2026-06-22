#define _CRT_SECURE_NO_WARNINGS

// List.h
// 下面的接口函数的实现放到List.cpp中
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


typedef int LDataType;

typedef struct ListNode {
    LDataType data;          // 存储数据
    struct ListNode* next;   // 存放后继结点地址
} LNode, * LinkList;


// 创建一个新结点
LNode* BuyListNode(int data);


// 初始化链表
LNode* ListInit();

// 书本上的一些用法
// void ListInit(LinkList& L);
// 等价于 void ListInit(LNode*& L);


// 打印链表
void ListPrint(LNode* L);

// 等价的
// void ListPrint(LinkList L);


// 获取链表中有效元素个数
int ListSize(LNode* L);


// 获取链表中第一个数据等于x结点的地址，若不存在返回NULL指针
LNode* ListLocateElem(LNode* L, LDataType x);


// 返回链表中下标为i的结点
LNode* ListGetElem(LNode* L, int i);


// 在链表的第i个下标位置插入元素x
void ListInsert(LNode* L, int i, LDataType x);


// 删除链表中下标为i的结点，并用x带出结点的值
LDataType ListDelete(LNode* L, int i);


// 检测链表是否为空，空返回真，否则返回假
bool ListEmpty(LNode* L);


// 头插
void ListPushFront(LNode* L, LDataType x);

// 尾插
void ListPushBack(LNode* L, LDataType x);

// 头删
LDataType ListPopFront(LNode* L);

// 尾删
LDataType ListPopBack(LNode* L);


// 销毁链表
void ListDestroy(LNode* L);