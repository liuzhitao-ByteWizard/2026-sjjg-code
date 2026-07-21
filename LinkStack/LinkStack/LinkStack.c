//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define SIZE 1000000
//
//// 顺序表测试
//void test_array() {
//    int* array = (int*)malloc(SIZE * sizeof(int));
//    for (int i = 0; i < SIZE; i++)
//        array[i] = i;
//
//    clock_t start = clock();
//    long long sum = 0;
//    for (int i = 0; i < SIZE; i++)
//        sum += array[i];
//    clock_t end = clock();
//
//    printf("Array time: %d ms, sum=%lld\n", end - start, sum);
//    free(array);
//}
//
//// 链表测试
//struct Node {
//    int data;
//    struct Node* next;
//};
//
//void test_linked_list() {
//    struct Node* head = NULL;
//
//    // 创建链表（可能不连续）
//    for (int i = SIZE - 1; i >= 0; i--) {
//        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
//        node->data = i;
//        node->next = head;
//        head = node;
//    }
//
//    clock_t start = clock();
//    long long sum = 0;
//    struct Node* curr = head;
//    while (curr) {
//        sum += curr->data;
//        curr = curr->next;  // 指针跳跃，缓存不友好
//    }
//    clock_t end = clock();
//
//    printf("LinkedList time: %d ms, sum=%lld\n", end - start, sum);
//
//    // 清理
//    while (head) {
//        struct Node* temp = head;
//        head = head->next;
//        free(temp);
//    }
//}
//
//int main() {
//    test_array();
//    test_linked_list();
//
//    return 0;
//}
//
//

#include "LinkStack.h"

void LinkStackInit(LinkStack* s) {
	assert(s);
	s->topHead = NULL;
	s->size = 0;
}

void LinkStackDestroy(LinkStack* s) {
	assert(s);
	assert(!LinkStackEmpty(s));
	LSNode* cur = s->topHead;
	while (cur) {
		LSNode* next = cur->next;
		free(cur);
		cur = next;
	}
	s->topHead = NULL;
	s->size = 0;
}

// x入栈
void LinkStackPush(LinkStack* s, STDataType x) {
    assert(s);

    // 1. 申请新结点
    LSNode* newNode = (LSNode*)malloc(sizeof(LSNode));
    if (NULL == newNode) {
        printf("LinkStackPush:申请节点失败");
        exit(-1);
    }

    newNode->data = x;

    // 头插
    newNode->next = s->topHead;
    s->topHead = newNode;
    s->size++;
}

// 出栈：删除栈顶结点，并返回栈顶元素
STDataType LinkStackPop(LinkStack* s) {
    // 栈对象必须有效，且空栈不能出栈
    assert(s);
    assert(!LinkStackEmpty(s));

    // 释放结点前，先保存栈顶数据
    STDataType top = s->topHead->data;

    // 保存原栈顶结点，并将栈顶下移到下一个结点
    LSNode* delNode = s->topHead;
    s->topHead = delNode->next;

    // 释放原栈顶结点，更新元素数量
    free(delNode);
    s->size--;

    return top;
}

int LinkStackSize(LinkStack* s) {
	assert(s);
	return s->size;
}

bool LinkStackEmpty(LinkStack* s) {
	assert(s);
	return s->topHead == NULL;
}

STDataType LinkStackTop(LinkStack* s) {
	assert(s);
	assert(!LinkStackEmpty(s));
	return s->topHead->data;
}