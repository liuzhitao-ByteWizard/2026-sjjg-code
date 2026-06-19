#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int SqDataType;   // 数据元素类型

typedef struct {
    SqDataType* arr;   // 动态数组指针
    int size;          // 当前有效数据个数
    int capacity;      // 当前容量
} SqList;


// 初始化顺序表
void SqListInit(SqList* ps);

// 销毁顺序表
void SqListDestroy(SqList* ps);

// 按下标获取元素
SqDataType GetElem(SqList* ps, int i);

// 查找元素，返回下标
int LocateElem(SqList* ps, SqDataType x);

// 在指定位置插入
void SqListInsert(SqList* ps, int i, SqDataType x);

// 删除指定位置元素
SqDataType SqListDelete(SqList* ps, int i);

// 打印顺序表
void SqListPrint(SqList* ps);

// 判空
bool EmptySqList(SqList* ps);

// 获取元素个数
int SqListSize(SqList* ps);

// 尾插 / 头插
void SqListPushBack(SqList* ps, SqDataType x);
void SqListPushFront(SqList* ps, SqDataType x);

// 尾删 / 头删
void SqListPopBack(SqList* ps);
void SqListPopFront(SqList* ps);