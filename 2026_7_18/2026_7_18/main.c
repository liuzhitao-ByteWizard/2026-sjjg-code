#define _CRT_SECURE_NO_WARNINGS
#include "1.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    int len1 = 1, len2 = 1;
//    struct ListNode* cur1 = headA, * cur2 = headB;
//    while (cur1)
//    {
//        cur1 = cur1->next;
//        len1++;
//    }
//    while (cur2)
//    {
//        cur2 = cur2->next;
//        len2++;
//    }
//
//    if (cur1 != cur2)
//        return NULL;
//
//    cur1 = headA;
//    cur2 = headB;
//    //算出两个链表之间的长度差异
//    int dif = abs(len1 - len2);
//    //让长的链表走差距步
//    if (len1 > len2)
//    {
//        while (dif--)
//            cur1 = cur1->next;
//    }
//    if (len2 > len1)
//    {
//        while (dif--)
//            cur2 = cur2->next;
//    }
//
//    //两个链表同时走
//    while (cur1 != cur2)
//    {
//        cur1 = cur1->next;
//        cur2 = cur2->next;
//    }
//    return cur1;
//}
//
//struct ListNode* detectCycle(struct ListNode* head) {
//    //判断是否为空链表
//    if (head == NULL)
//        return false;
//
//    //判断链表是否成环    
//    struct ListNode* fast = head, * slow = head;
//    while (fast && fast->next)
//    {
//        fast = fast->next->next;
//        slow = slow->next;
//        if (slow == fast)
//        {
//            //断开相遇结点处
//            struct ListNode* newhead = slow->next;
//            slow->next = NULL;
//
//            struct ListNode* intersect = getIntersectionNode(head, newhead);
//            slow->next = newhead;
//            return intersect;
//        }
//    }
//    return false;
//}

int main()
{
    Stack s;
    StackInit(&s);

    // 入栈，检测栈顶数据元素 和 栈中有效数据元素是否正确
    StackPush(&s, 1);
    StackPush(&s, 2);
    StackPush(&s, 3);
    StackPush(&s, 4);
    StackPush(&s, 5);
    //printf("栈中元素总数为：%d\n", StackSize(&s));
    printf("栈顶元素为：%d\n", StackTop(&s));

    // 出栈
    printf("出栈：栈顶元素为：%d\n", StackPop(&s));
    printf("出栈：栈顶元素为：%d\n", StackPop(&s));
    printf("出栈：栈顶元素为：%d\n", StackPop(&s));
    printf("出栈：栈顶元素为：%d\n", StackPop(&s));
    printf("出栈：栈顶元素为：%d\n", StackPop(&s));

    // 断言报错
    //printf("出栈：栈顶元素为：%d\n", StackPop(&s));
    //printf("栈顶元素为：%d\n", StackTop(&s));

    StackPush(&s, 6);
    StackPush(&s, 7);

    // 出栈
    printf("出栈：栈顶元素为：%d\n", StackPop(&s));
    printf("出栈：栈顶元素为：%d\n", StackPop(&s));

    StackDestroy(&s);

    return 0;
}



