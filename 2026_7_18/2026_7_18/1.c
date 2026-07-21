#define _CRT_SECURE_NO_WARNINGS
#include "1.h"

void StackInit(Stack* s)
{
	assert(s);

	s->arr = (STDataType*)malloc(4 * sizeof(STDataType));

	if (s->arr == NULL)
	{
		perror("use malloc");
		return;
	}

	s->top = 0; //指向的是栈顶元素的下一个位置
	s->capacity = 4;
}

void StackDestroy(Stack* s)
{
	assert(s);

	free(s->arr);
	s->arr = NULL;
	s->top = 0;
	s->capacity = 0;
}

void StackPush(Stack* s, STDataType x)
{
	assert(s);

	if (s->top == s->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(s->arr, 2 * s->capacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		s->arr = tmp;
		s->capacity *= 2;
	}

	s->arr[s->top++] = x;
}

STDataType StackPop(Stack* s)
{
	assert(s);
	STDataType tmp = s->arr[s->top - 1];
	s->top--;
	return tmp;
}

STDataType StackTop(Stack* s)
{
	assert(s);

	assert(!StackEmpty(s));


	return s->arr[s->top - 1];
}

int StackSize(Stack* s)
{
	assert(s);
	return s->top;
}

bool StackEmpty(Stack* s)
{
	assert(s);
	return s->top == 0;
}