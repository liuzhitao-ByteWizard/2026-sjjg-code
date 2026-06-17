#define _CRT_SECURE_NO_WARNINGS
#include "SqList.h"

void SqListInit(SqList* ps)
{
	assert(ps); //确保传过来的动态顺序表地址不为空

	ps->arr = (SqDataType*)malloc(4 * sizeof(SqDataType));
	if (ps->arr == NULL)
	{
		//申请失败，退出程序
		perror("use malloc\n");
		return;
	}
	ps->size = 0;
	ps->capacity = 4;
}

////初始化顺序表
//void SqListInit(SqList& ps)
//{
//	// ps 是引用，正常情况下不能为空，因此不需要像指针那样 assert(ps)	
//	ps.arr = (SqDataType*)malloc(4 * sizeof(SqDataType));
//
//	if (ps.arr == NULL)
//	{
//		perror("use malloc\n");
//		return;
//	}
//
//	ps.size = 0;
//	ps.capacity = 4;
//}

//void SqListDestory(SqList* ps)
//{
//	// 防止空指针访问
//	assert(ps);
//
//	// 1. 释放堆区动态数组空间
//	//    该空间由 malloc / realloc 申请
//	free(ps->arr);
//
//	// 2. 防止野指针（置空指针）
//	ps->arr = NULL;
//
//	// 3. 清空逻辑信息（表示结构体已“失效/空”）
//	ps->size = 0;
//	ps->capacity = 0;
//}

// 在顺序表第 i 个位置 (下标i) 插入元素 x
void SqListInsert(SqList* ps, int i, SqDataType x)
{
    // 1. 检查指针是否有效（防止空指针）
    assert(ps);

    // 2. 检查插入位置是否合法（i 可以等于 size，表示尾插）
    assert(i >= 0 && i <= ps->size);

    /*
    // 如果不用 assert，也可以用这种方式做提示式判断
    if (i < 0 || i > ps->size)
    {
        printf("请在[0, %d]范围内插入\n", ps->size);
        return;
    }
    */

    // 3. 判断是否需要扩容（当前空间已满）
    if (ps->size == ps->capacity)
    {
        // 扩容：通常扩大 2 倍
        // realloc：重新申请更大空间，并可能搬移数据
        SqDataType* tmp =(SqDataType*)realloc(ps->arr,sizeof(SqDataType) * ps->capacity * 2);

        // 4. 判断 realloc 是否成功
        if (tmp == NULL)
        {
            printf("SqListInsert: 内存申请空间失败!!!\n");
            return;
        }

        // 5. 更新指针和容量
        ps->arr = tmp;
        ps->capacity *= 2;
    }

    // 6. 从后往前移动数据，为插入腾出位置
    // j 从最后一个有效元素开始，依次后移
    for (int j = ps->size - 1; j >= i; j--)
    {
        ps->arr[j + 1] = ps->arr[j];
    }

    // 7. 在 i 位置插入新元素
    ps->arr[i] = x;

    // 8. 有效元素个数 +1
    ps->size++;
}