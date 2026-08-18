#define _CRT_SECURE_NO_WARNINGS
#include "1.h"
//
//void StackInit(Stack* s) {
//	assert(s);
//
//	STDataType* tmp = (STDataType*)malloc(sizeof(STDataType) * 4);
//	if (tmp == NULL) {
//		perror("malloc fail");
//		return;
//	}
//	//为数组分配空间
//	s->arr = tmp;
//	s->capacity = 4;
//	//指向栈空间有效元素的下一个位置
//	s->top = 0;
//
//}
//
//void StackDestroy(Stack* s) {
//	assert(s);
//
//	free(s->arr);
//	s->arr = NULL;
//	s->capacity = 0;
//	s->top = 0;
//}
//
//void StackPush(Stack* s, STDataType x) {
//	assert(s);
//
//	//扩容
//	if (s->top == s->capacity) {
//		//默认扩容是扩两倍
//		STDataType* tmp = (STDataType*)realloc(s->arr, sizeof(STDataType) * s->capacity * 2);
//		if (tmp == NULL) {
//			perror("realloc fail");
//			return;
//		}
//		//将空间给s->arr后，动态开辟的tmp会自动还给操作系统
//		s->arr = tmp;
//		s->capacity *= 2;
//	}
//
//	//入栈
//	s->arr[s->top++] = x;
//}
//
//STDataType StackPop(Stack* s) {
//	assert(s);
//
//	//判断栈是否为空
//	if (StackEmpty(s))
//		return NULL;
//
//	STDataType tmp = s->arr[s->top - 1];
//	s->top--;
//	return tmp;
//}
//
//STDataType StackTop(Stack* s)
//{
//	assert(s);  // 保证栈指针有效
//
//	// 保证栈不为空，空栈不能取栈顶元素
//	assert(!StackEmpty(s));
//
//	// top 指向栈顶元素的下一个位置
//	// 因此栈顶元素的位置是 top - 1
//	return s->arr[s->top - 1];
//}
//
//int StackSize(Stack* s)
//{
//	assert(s);
//	return s->top;
//}
//
//bool StackEmpty(Stack* s)
//{
//	assert(s);  // 保证栈指针有效
//
//	// top == 0 表示栈中没有元素
//	// 因此返回 true，表示栈为空
//	return s->top == 0;
//}
//
//int main()
//{
//	Stack s;
//	StackInit(&s);
//
//	// 入栈，检测栈顶数据元素 和 栈中有效数据元素是否正确
//	StackPush(&s, 1);
//	StackPush(&s, 2);
//	StackPush(&s, 3);
//	StackPush(&s, 4);
//	StackPush(&s, 5);
//	//printf("栈中元素总数为：%d\n", StackSize(&s));
//	printf("栈顶元素为：%d\n", StackTop(&s));
//
//	// 出栈
//	printf("出栈：栈顶元素为：%d\n", StackPop(&s));
//	printf("出栈：栈顶元素为：%d\n", StackPop(&s));
//	printf("出栈：栈顶元素为：%d\n", StackPop(&s));
//	printf("出栈：栈顶元素为：%d\n", StackPop(&s));
//	printf("出栈：栈顶元素为：%d\n", StackPop(&s));
//
//	// 断言报错
//	//printf("出栈：栈顶元素为：%d\n", StackPop(&s));
//	//printf("栈顶元素为：%d\n", StackTop(&s));
//
//	StackPush(&s, 6);
//	StackPush(&s, 7);
//
//	// 出栈
//	printf("出栈：栈顶元素为：%d\n", StackPop(&s));
//	printf("出栈：栈顶元素为：%d\n", StackPop(&s));
//
//	StackDestroy(&s);
//
//	return 0;
//}

void LinkStackInit(LinkStack* s) {
	assert(s);

	s->topHead = NULL;
	s->size = 0;
}

void LinkStackDestroy(LinkStack* s) {
	assert(s);

	LSNode* cur = s->topHead;

	while (cur) {
		LSNode* next = cur->next;
		free(cur);
		cur = next;
	}
	s->topHead = NULL;
	s->size = 0;
}

void LinkStackPush(LinkStack* s, STDataType x) {
	assert(s);

	// 1. 申请新结点
	LSNode* newNode = (LSNode*)malloc(sizeof(LSNode));
	if (NULL == newNode) {
		printf("LinkStackPush:申请节点失败");
		exit(-1);
	}
	newNode->data = x;

	newNode->next = s->topHead;
	s->topHead = newNode;
	s->size++;
}

STDataType LinkStackPop(LinkStack* s) {
	assert(s);

	//判断栈是否为空
	if (LinkStackEmpty(s))
		return -1;

	LSNode* delNode = s->topHead;
	STDataType tmp = delNode->data;

	s->topHead = delNode->next;
	free(delNode);
	s->size--;
	return tmp;
}

STDataType LinkStackTop(LinkStack* s) {
	assert(s);
	assert(!LinkStackEmpty(s));

	return s->topHead->data;
}

int LinkStackSize(LinkStack* s) {
	assert(s);
	return s->size;
}

// 检测栈是否为空，如果是空返回真，否则返回假
bool LinkStackEmpty(LinkStack* s) {
	assert(s);

	return s->topHead == NULL;
}

int main() {
	LinkStack s;
	LinkStackInit(&s);

	// 入栈，检测栈顶数据元素和栈中有效数据元素是否正确
	LinkStackPush(&s, 1);
	LinkStackPush(&s, 2);
	LinkStackPush(&s, 3);
	printf("出栈：栈顶元素为：%d\n", LinkStackPop(&s));
	printf("出栈：栈顶元素为：%d\n", LinkStackPop(&s));

	LinkStackPush(&s, 4);
	LinkStackPush(&s, 5);
	printf("栈中元素总数为：%d\n", LinkStackSize(&s));
	printf("栈顶元素为：%d\n", LinkStackTop(&s));

	// 出栈
	printf("出栈：栈顶元素为：%d\n", LinkStackPop(&s));
	printf("出栈：栈顶元素为：%d\n", LinkStackPop(&s));
	printf("出栈：栈顶元素为：%d\n", LinkStackPop(&s));
	// printf("出栈：栈顶元素为：%d\n", LinkStackPop(&s));
	// printf("出栈：栈顶元素为：%d\n", LinkStackPop(&s));

	// 断言报错
	// printf("出栈：栈顶元素为：%d\n", LinkStackPop(&s));

	// LinkStackDestroy(&s);

	return 0;
}