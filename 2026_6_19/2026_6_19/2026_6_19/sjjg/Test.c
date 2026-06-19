#define _CRT_SECURE_NO_WARNINGS
#include "SqList.h"

//void TestSqList1() {
//    SqList L;
//    SqListInit(&L);
//    SqListInsert(&L, 0, 9);
//    SqListInsert(&L, 1, 10);
//    SqListInsert(&L, 2, 20);
//    SqListInsert(&L, 3, 30);
//    SqListInsert(&L, 4, 40);
//    SqListInsert(&L, 5, 50);  // 扩容
//    SqListPrint(&L);
//
//    // 头插
//    SqListInsert(&L, 0, 0);
//    SqListPrint(&L);
//
//    // 尾插
//    SqListInsert(&L, SqListSize(&L), 60);
//    SqListPrint(&L);
//
//    // 中间插入
//    SqListInsert(&L, 2, 2);
//    SqListPrint(&L);
//}

void TestSqList2() {
    SqList L;
    SqListInit(&L);
    SqListInsert(&L, 0, 9);
    SqListInsert(&L, 1, 10);
    SqListInsert(&L, 2, 20);
    SqListInsert(&L, 3, 30);
    SqListInsert(&L, 4, 40);
    SqListInsert(&L, 5, 50);  // 扩容
    SqListPrint(&L);

    // 删除顺序表第1个位置上的元素
    printf("顺序表中有效元素个数为：%d\n", SqListSize(&L));
    // 删除第一个数据
    printf("删除的元素是:%d \n", SqListDelete(&L, 0));

    // 删除末尾的数据
    printf("删除的元素是:%d \n", SqListDelete(&L, SqListSize(&L) - 1));

    // 删除中间的数据
    printf("删除的元素是:%d \n", SqListDelete(&L, 2));

    SqListPrint(&L);
    printf("顺序表中第%d个元素是：%d\n", 1, GetElem(&L, 1));

    printf("40 的下标是%d\n", LocateElem(&L, 40));
    SqListDestroy(&L);
}

int main() {
    //TestSqList1();
    TestSqList2();

    return 0;
}