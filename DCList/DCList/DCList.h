#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DCLDataType;

typedef struct DCListNode {
    DCLDataType data;          // 存储数据元素的值
    struct DCListNode* prev;   // 存放前驱结点指针
    struct DCListNode* next;   // 存放后继结点指针
} DCListNode;


// 链表初始化
DCListNode* DCListInit();


// 销毁链表
void DCListDestroy(DCListNode* L);


// 获取链表的第 i 个结点
DCListNode* DCListGetElem(DCListNode* L, int i);


// 在 pos 位置插入值为 x 的结点
void DCListInsert(DCListNode* pos, DCLDataType x);


// 删除 pos 位置的结点
void DCListDelete(DCListNode* pos);


// 头插
void DCListPushFront(DCListNode* L, DCLDataType x);


// 尾插
void DCListPushBack(DCListNode* L, DCLDataType x);


// 头删
void DCListPopFront(DCListNode* L);


// 尾删
void DCListPopBack(DCListNode* L);


// 打印链表元素
void DCListPrint(DCListNode* L);