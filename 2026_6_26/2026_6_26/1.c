#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

 /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     struct ListNode *next;
  * };
  */
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//
//    struct ListNode guand; //创建哨兵位的结点;
//    struct ListNode* newhead = NULL, * tail = NULL;
//    newhead = tail = &guand;
//
//    // //当两个链表有一个为空的情况下
//    // if(list1 == NULL)
//    //     return list2;
//    // if(list2 == NULL)
//    //     return list1;
//
//
//    while (list1 && list2)
//    {
//        if (list1->val > list2->val)
//        {
//            // //1.判断是否为空表
//            // if(newhead == NULL)
//            //     newhead = tail = list2;
//            // else
//            // {
//                //1.不为空的情况下进行尾插
//            tail->next = list2;
//            tail = list2;
//            // }
//            //2.跳过该比较结点，找到下一个带比较结点
//            list2 = list2->next;
//        }
//        else
//        {
//            // //判断是否为空表
//            // if(newhead == NULL)
//            //     newhead = tail = list1;
//            // else
//            // {
//                //不为空的情况下进行尾插
//            tail->next = list1;
//            tail = list1;
//            // }
//            //2.跳过该比较结点，找到下一个带比较结点
//            list1 = list1->next;
//        }
//    }
//
//    if (list1)
//        //不为空的情况下，当前尾结点的下一个位置只想另一个链表的结点
//        tail->next = list1;
//    if (list2)
//        tail->next = list2;
//
//    return newhead->next;
//}

//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//
//    // 双指针用于遍历两条链表
//    struct ListNode* curA = headA, * curB = headB;
//
//    // 计算链表A长度（从1开始计数，curA初始指向第一个结点）
//    int lenA = 1;
//    while (curA->next) {
//        curA = curA->next;
//        ++lenA;
//    }
//
//    // 计算链表B长度
//    int lenB = 1;
//    while (curB->next) {
//        curB = curB->next;
//        ++lenB;
//    }
//
//    // 如果尾结点不同，则两链表一定不相交（相交链表的尾结点一定相同）
//    if (curA != curB) {
//        return NULL;
//    }
//
//    // 计算长度差，用于对齐两条链表起点
//    int gap = abs(lenA - lenB);
//
//    // longList 指向较长链表，shortList 指向较短链表
//    struct ListNode* longList = headA, * shortList = headB;
//
//    // 判断谁是长链表，进行交换
//    if (lenA < lenB) {
//        longList = headB;
//        shortList = headA;
//    }
//
//    // 长链表先走 gap 步，使两条链表剩余长度一致
//    while (gap--) {
//        longList = longList->next;
//    }
//
//    // 两个指针同步移动，直到指向同一个结点
//    // 第一个相同结点即为交点
//    while (longList != shortList) {
//        longList = longList->next;
//        shortList = shortList->next;
//    }
//
//    // 返回交点（或 NULL）
//    return longList;
//}

//bool hasCycle(struct ListNode* head)
//{
//    // 定义快慢指针，初始都指向头结点
//    struct ListNode* slow = head, * fast = head;
//
//    // 快指针每次走两步，慢指针每次走一步
//    // 只要 fast 和 fast->next 不为空，就可以继续走
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//
//        // 如果快慢指针相遇，说明链表中存在环
//        if (slow == fast)
//            return true;
//    }
//
//    // 如果快指针走到 NULL，说明没有环
//    return false;
//}

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head, * fast = head;

    //1.用快慢指针判断是否存在环
    while (fast && fast->next) {

        // slow 每次走一步
        slow = slow->next;

        // fast 每次走两步
        fast = fast->next->next;

        // 若快慢指针相遇，说明存在环
        if (slow == fast) {
            //2.寻找环的入口节点
            // meet 为快慢相遇点
            struct ListNode* meet = slow;

            // 将相遇点之后的节点暂时作为新链表头
            struct ListNode* newhead = meet->next;

            // 断开相遇点，临时把环“切开”，转换为相交链表问题
            meet->next = NULL;

            // 通过两个链表相交问题求入环点：
            // head -> 原链表头
            // newhead -> 环内剩余链表
            struct ListNode* entry = getIntersectionNode(head, newhead);

            // 恢复原链表结构（重新连接成环）
            meet->next = newhead;

            // 返回入环点
            return entry;
        }
    }
    // fast 走到空，说明不存在环
    return NULL;
}