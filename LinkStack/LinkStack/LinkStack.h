#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// 链式栈中存储的数据元素类型
typedef int STDataType;

// 链式栈底层单链表中结点的定义
typedef struct LinkStackNode {
    struct LinkStackNode* next;
    STDataType data;
} LSNode;

// 链式栈结构的定义
typedef struct {
    LSNode* topHead;  // 栈顶结点指针
    int size;         // 栈中数据个数
} LinkStack;

// 初始化链式栈
void LinkStackInit(LinkStack* s);

// 销毁链式栈
void LinkStackDestroy(LinkStack* s);

// 入栈
void LinkStackPush(LinkStack* s, STDataType x);

// 出栈，并返回栈顶元素
STDataType LinkStackPop(LinkStack* s);

// 获取栈顶元素
STDataType LinkStackTop(LinkStack* s);

// 获取栈中有效元素个数
int LinkStackSize(LinkStack* s);

// 检测栈是否为空，如果是空返回真，否则返回假
bool LinkStackEmpty(LinkStack* s);