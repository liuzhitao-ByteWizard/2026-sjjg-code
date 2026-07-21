#define _CRT_SECURE_NO_WARNINGS

#pragma once

// Stack.h
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct {
    STDataType* arr;  // 指向栈数组空间的指针
    int top;          // 栈顶位置
    int capacity;     // 容量
}Stack;

// 栈的初始化
void StackInit(Stack* s);
// 栈的销毁
void StackDestroy(Stack* s);

// x元素入栈(进栈)
void StackPush(Stack* s, STDataType x);
// 将栈顶元素出栈，并用返回栈顶元素
STDataType StackPop(Stack* s);
// 获取栈顶元素并返回
STDataType StackTop(Stack* s);

// 获取栈中有效元素个数
int StackSize(Stack* s);
// 检测栈是否为空，如果是空返回真，否则返回假
bool StackEmpty(Stack* s);
