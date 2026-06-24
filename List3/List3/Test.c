// main.c
#include "List.h"

LNode* CreateList() {
    // 创建头结点
    LNode* L = BuyListNode(-1);

    // 先快速构造5个结点，方便测试
    LNode* node1 = BuyListNode(1);
    LNode* node2 = BuyListNode(2);
    LNode* node3 = BuyListNode(3);
    LNode* node4 = BuyListNode(4);
    LNode* node5 = BuyListNode(5);

    // 然后通过手动的方式将结点链接起来
    L->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    return L;
}

// 书上喜欢写的一种创建链表方式，这种方式不方便测试和调试
//void CreateList(LinkList& L) {
//    // 创建头结点
//    L = BuyListNode(-1);
//
//    printf("请依次输入一组数据，以-1结束:>");
//    int x = 0;
//    scanf("%d", &x);
//    while (x != -1)
//    {
//        LNode* node = BuyListNode(x);
//        // 头插
//        node->next = L->next;
//        L->next = node;
//
//        scanf("%d", &x);
//    }
//}

//void TestList1() {
//    LNode* LT = NULL;
//    LT = CreateList();
//
//    // 测试打印方法和获取结点个数方法
//    printf("链表LT中总共有%d个结点\n", ListSize(LT));
//    ListPrint(LT);
//
//    // 测试按值获取
//    printf("链表中值%d结点为%p\n", 1, ListLocateElem(LT, 1));
//    printf("链表中值%d结点为%p\n", 3, ListLocateElem(LT, 2));
//    printf("链表中值%d结点为%p\n", 100, ListLocateElem(LT, 100));
//
//    // 测试按下标获取
//    printf("链表中下标%d的结点的值为%d\n", 0, ListGetElem(LT, 0)->data);
//    printf("链表中下标%d的结点的值为%d\n", 2, ListGetElem(LT, 2)->data);
//    printf("链表中下标%d的结点的值为%d\n", 4, ListGetElem(LT, 4)->data);
//    printf("链表中下标%d的结点的值为%p\n", 100, ListGetElem(LT, 100));
//
//    // 销毁链表
//    ListDestroy(LT);
//}

void TestList2() {
    LNode* LT = NULL;
    LT = CreateList();
    ListPrint(LT);

    ListInsert(LT, 5, 6);   // 尾插
    ListPrint(LT);
    ListInsert(LT, 2, 30);  // 中间插
    ListPrint(LT);
    ListInsert(LT, 0, 0);   // 头插
    ListPrint(LT);

    // 非法位置
    //ListInsert(LT, 100, 100);
    printf("\n\n");

    // 测试不使用CreateList创建链表
    /*
    LNode* LT = ListInit();
    ListInsert(LT, 0, 1);
    ListInsert(LT, 1, 2);
    ListInsert(LT, 2, 3);
    ListPrint(LT);
    */

    ListDelete(LT, 0);  // 头删
    ListPrint(LT);
    ListDelete(LT, 2);  // 中间删
    ListPrint(LT);
    ListDelete(LT, 5);  // 尾删
    ListPrint(LT);

    // 非法位置
    //ListDelete(LT, 100);

    // 销毁链表
    //ListDestroy(LT);
}

int main() {
    //TestList1();
    TestList2();

    return 0;
}