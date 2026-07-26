#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;  // 队列中存储数据元素的类型

// 采用单链表实现队列，链表结点的定义
typedef struct LinkNode {
    QDataType data;
    struct LinkNode* next;
} QNode;

typedef struct {
    QNode* front;
    QNode* rear;
    int size;
} LinkQueue;

// 初始化队列
void QueueInit(LinkQueue* q);

// 销毁队列
void QueueDestroy(LinkQueue* q);

// 检测队列是否为空，空返回真，否则返回假
bool QueueEmpty(LinkQueue* q);

// 获取队列中有效元素个数
int QueueSize(LinkQueue* q);

// 获取队头元素
QDataType QueueFront(LinkQueue* q);

// 将 x 入队列
void EnQueue(LinkQueue* q, QDataType x);

// 出队并返回队头数据
QDataType DeQueue(LinkQueue* q);