#define _CRT_SECURE_NO_WARNINGS
#include "DCList.h"

//typedef int DLDataType;
//
//typedef struct DListNode {
//    DLDataType data;              // 存放数据元素
//    struct DListNode* prev;       // 指向前驱结点
//    struct DListNode* next;       // 指向后继结点
//} DNode, * DLinkList;
//
//void InitList(LinkList& L)
//{
//    L = BuyListNode(-1);
//    L->next = NULL;
//}
//
//void InitCList(CLinkList& L)
//{
//    L = Buylistnode(-1);
//    L->next = L;
//}


// 创建一个新结点
DCListNode* BuyDCListNode(int data) {
    // 不能创建一个LNode的结构体变量，因为局部变量出了作用域就销毁了
    // 所以这里用malloc从堆上动态申请结点，并检测是否申请成功
    DCListNode* newNode = (DCListNode*)malloc(sizeof(DCListNode));
    if (NULL == newNode) {
        printf("BuyListNode失败!!!\n");
        exit(-1);
    }

    // 申请成功后，对结点中的数据域和指针域进行初始化
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// 链表初始化
DCListNode* DCListInit() {
    DCListNode* L = BuyDCListNode(-1);
    L->next = L;
    L->prev = L;

    return L;
}

void DCListDestroy(DCListNode* L)
{
    assert(L);
    DCListNode* cur = L->next;
    //销毁中间结点
    while (cur != L)
    {
        DCListNode* next = cur->next;
        free(cur);
        cur = next;
    }
    //销毁头结点
    free(L);
    L = NULL;
}

// 获取链表的下标i的结点
DCListNode* DCListGetElem(DCListNode* L, int i) {
    assert(L);
    assert(i >= 0);

    // 2. 从链表头结点之后开始，逐个往后找第i个结点
    DCListNode* cur = L->next;
    int j = 0;
    while (cur != L && j < i) {
        cur = cur->next;
        ++j;
    }

    // j < i说明没第i个结点，参数i非法
    assert(j == i);

    return cur;
}

// 打印链表中的元素
void DCListPrint(DCListNode* L) {
    // 从前往后打印链表
    //printf("头结点->");
    DCListNode* cur = L->next;
    while (cur != L) {
        printf("%d->", cur->data);
        cur = cur->next;
    }

    printf("\n");

    // 从后往前打印链表
   /* cur = L->prev;
    while (cur != L) {
        printf("%d->", cur->data);
        cur = cur->prev;
    }
    printf("\n");*/
}


// 在pos位置后插入值为x的结点
void DCListInsert(DCListNode* pos, DCLDataType x) {
    assert(pos);

    DCListNode* newNode = BuyDCListNode(x);

    // 无关顺序
    //DCListNode* posNext = pos->next;
    //pos->next = newNode;
    //newNode->prev = pos;
    //newNode->next = posNext;
    //posNext->prev = newNode;


    // 注意顺序
    newNode->next = pos->next;
    pos->next->prev = newNode;

    pos->next = newNode;
    newNode->prev = pos;
}

// 删除 pos 位置的结点
void DCListDelete(DCListNode* pos)
{
    assert(pos);

    //不用关心顺序
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;

    free(pos);
    pos = NULL;
}