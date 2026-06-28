#define _CRT_SECURE_NO_WARNINGS
#include "DCList.h"

int main() {

    // 以头插法创建链表
    DCListNode* L = DCListInit();

    // 头插
    DCListInsert(L, 1);
    DCListInsert(L, 2);
    DCListInsert(L, 3);
    DCListInsert(L, 4);
    DCListPrint(L);

    // 尾插
    DCListInsert(L->prev, 5);
    DCListInsert(L->prev, 6);
    DCListInsert(L->prev, 7);
    DCListInsert(L->prev, 8);
    DCListPrint(L);

    // 头删
    DCListDelete(L->next);
    DCListDelete(L->next);
    DCListPrint(L);

    // 尾删
    DCListDelete(L->prev);
    DCListDelete(L->prev);
    DCListPrint(L);

    // 中间插入
    DCListInsert(DCListGetElem(L, 2), 100);
    DCListPrint(L);

    // 中间删除
    DCListDelete(DCListGetElem(L, 2));
    DCListPrint(L);

    // 销毁链表
    DCListDestroy(L);

    return 0;
}