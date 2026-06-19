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

//// 我们实现的时候，i用的是下标
//// 在顺序表的第i个位置插入元素x
//void SqListInsert(SqList* ps, int i, SqDataType x) {
//    assert(ps);
//    assert(i <= ps->size);
//
//    // 满了扩容
//    if (ps->size == ps->capacity) {
//        // 满了扩容
//        SqDataType* tmp = (SqDataType*)realloc(ps->arr, sizeof(SqDataType) * ps->capacity * 2);
//        if (tmp == NULL) {
//            printf("SqListInsert: 内存申请空间失败!!!\n");
//            return;
//        }
//
//        ps->arr = tmp;
//        ps->capacity *= 2;
//    }
//
//    // 挪动数据
//    int j = ps->size - 1;
//    while (j >= i) {
//        ps->arr[j + 1] = ps->arr[j];
//        --j;
//    }
//    ps->arr[i] = x;
//    ps->size++;
//}

// 在顺序表第 i 个位置插入元素 x
void SqListInsert(SqList* ps, int i, SqDataType x)
{
    // 1. 检查指针是否合法，防止空指针访问
    assert(ps);

    // 2. 检查插入位置是否合法（i 可以等于 size，表示尾插）
    assert(i <= ps->size);

    // 3. 判断是否需要扩容（当前顺序表已满）
    if (ps->size == ps->capacity)
    {
        // 使用 realloc 扩展为原容量的 2 倍
        // 注意：realloc 可能原地扩容，也可能异地扩容
        SqDataType* tmp =
            (SqDataType*)realloc(ps->arr,
                sizeof(SqDataType) * ps->capacity * 2);

        // 4. 判断扩容是否成功
        if (tmp == NULL)
        {
            printf("SqListInsert: 内存申请空间失败!!!\n");
            return;
        }

        // 5. 更新指针和容量
        // 如果是异地扩容，这里会指向新空间
        ps->arr = tmp;
        ps->capacity *= 2;
    }

    // 6. 数据搬移：从后往前挪动元素，为插入腾出位置
    // j 从最后一个有效元素开始，逐个后移
    int j = ps->size - 1;
    while (j >= i)
    {
        ps->arr[j + 1] = ps->arr[j];
        --j;
    }

    // 7. 在第 i 个位置插入新元素 x
    ps->arr[i] = x;

    // 8. 有效元素个数 +1
    ps->size++;
}

SqDataType GetElem(SqList* ps, int i)
{
	assert(ps);

	//检查查找位置是否合法
	assert(i >= 0 && i <= ps->size);

	return ps->arr[i];

}

int LocateElem(SqList* ps, SqDataType x)
{
    assert(ps);

    for (int i = 0; i < ps->size; i++)
    {
        if (ps->arr[i] == x)
            return i;
    }
    return -1;
}

void SqListPrint(SqList* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
}