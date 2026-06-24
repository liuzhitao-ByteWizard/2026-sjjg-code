#define _CRT_SECURE_NO_WARNINGS

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//struct ListNode* reverseList(struct ListNode* head)
//{
//	struct ListNode* newhead = head;
//	struct ListNode* cur = head;
//	while (cur)
//	{
//		cur->next = newhead->next;
//		newhead = cur;
//		cur = cur->next;
//	}
//	return newhead;
//}