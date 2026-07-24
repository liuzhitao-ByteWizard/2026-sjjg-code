#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//struct ListNode* removeElements(struct ListNode* head, int val) {
//    struct ListNode* prev = NULL, * cur = head;
//    while (cur)
//    {
//        if (cur->val == val)
//        {
//            //1.头删操作
//            if (prev == NULL)
//            {
//                head = cur->next;
//                free(cur);
//                cur = head;
//            }
//            else
//            {
//                struct ListNode* next = cur->next;
//                prev->next = next;
//                free(cur);
//                cur = next;
//            }
//        }
//        else
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//    }
//    return head;
//}

//struct ListNode* reverseList(struct ListNode* head) {
//    struct ListNode* newhead = NULL;
//    struct ListNode* cur = head;
//    while (cur)
//    {
//        struct ListNode* next = cur->next;
//
//        cur->next = newhead;
//        newhead = cur;
//
//        cur = next;
//    }
//    return newhead;
//}

//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    struct ListNode* cur1 = list1, * cur2 = list2;
//    struct ListNode* newhead = NULL;
//    struct ListNode* tail = NULL;
//    //如果有一个链表为空的情况下
//    if (cur1 == NULL && cur2)
//        return list2;
//    if (cur1 && cur2 == NULL)
//        return list1;
//
//    while (cur1 && cur2)
//    {
//        struct ListNode* next1 = cur1->next;
//        struct ListNode* next2 = cur2->next;
//        if (cur1->val >= cur2->val)
//        {
//
//            //判断链表是否为空
//            if (newhead == NULL)
//                tail = newhead = cur2;
//            else
//            {
//                cur2->next = tail->next;
//                tail->next = cur2;
//                tail = cur2;
//            }
//            cur2 = next2;
//        }
//        else
//        {
//            //判断链表是否为空
//            if (newhead == NULL)
//                tail = newhead = cur1;
//            else
//            {
//                cur1->next = tail->next;
//                tail->next = cur1;
//                tail = cur1;
//            }
//            cur1 = next1;
//        }
//    }
//    if (cur1)
//        tail->next = cur1;
//    if (cur2)
//        tail->next = cur2;
//
//    return newhead;
//}
//
//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* slow = head, * fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}
//
//struct ListNode* reverseList(struct ListNode* head) {
//    // newhead 用于保存“新链表的头结点”，初始为空
//    struct ListNode* newhead = NULL;
//
//    // cur 用于遍历原链表
//    struct ListNode* cur = head;
//
//    // 遍历原链表，直到为空
//    while (cur) {
//
//        // 1. 先保存当前结点的下一个结点（防止断链）
//        struct ListNode* next = cur->next;
//
//        // 2. 头插操作：将 cur 插入到新链表的头部
//        cur->next = newhead;
//        newhead = cur;
//
//        // 3. cur 后移，继续处理下一个结点
//        cur = next;
//    }
//
//    // 返回反转后的新链表头结点
//    return newhead;
//}
//
//void reorderList(struct ListNode* head) {
//
//    // 1. 找到链表中点（slow/fast 或中点函数）
//    struct ListNode* mid = middleNode(head);
//
//    // 2. 将链表从中点断开，分成前后两段
//    struct ListNode* newhead = mid->next; // 后半段起点
//    mid->next = NULL;                     // 断开前后链表
//
//    // 3. 反转后半段链表
//    newhead = reverseList(newhead);
//
//    // 4. cur1 指向前半段，curn 指向反转后的后半段
//    struct ListNode* cur1 = head;     // 前半段指针
//    struct ListNode* curn = newhead;  // 后半段指针
//
//    // 5. 依次交叉合并两个链表
//    while (curn) {
//
//        // 保存后半段当前节点的下一个节点（防止断链）
//        struct ListNode* nextn = curn->next;
//
//        // 将后半段当前节点插入到前半段当前节点后面
//        curn->next = cur1->next;
//        cur1->next = curn;
//
//        // 前半段指针后移两步（跳过刚插入的节点）
//        cur1 = cur1->next->next;
//
//        // 后半段指针后移
//        curn = nextn;
//    }
//}