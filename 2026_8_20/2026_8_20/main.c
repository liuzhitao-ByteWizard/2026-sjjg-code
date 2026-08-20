#define _CRT_SECURE_NO_WARNINGS
//int sumOfLeftLeaves(struct TreeNode* root) {
//    // 如果root为NULL，则直接返回0
//    if (root == NULL)
//        return 0;
//
//    int sum = 0;
//
//    // 如果左子树根节点不为空，且左子树根节点的左右子树均为空，则进行结果累加
//    if (root->left && root->left->left == NULL && root->left->right == NULL)
//        sum += root->left->val;
//
//    // 递归遍历查找左右子树中，满足左叶子节点性质的节点，并进行累加
//    sum += sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
//
//    // 返回sum结果，递归过程中是向上层交付计算结果
//    return sum;
//}

// 判断两棵树是否相同：
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)
//        return true;
//
//    if (p == NULL || q == NULL)
//        return false;
//
//    // 如果p和q两个节点值相等，则继续递归判断左右子树中两棵树的节点值是否相等
//    if (p->val == q->val)
//        return isSameTree(p->left, q->left) &&
//        isSameTree(p->right, q->right);
//
//    return false;
//}
//
//
//// 判断是否为另一棵树的子树：
//bool isSubtree(struct TreeNode* root, struct TreeNode* subroot) {
//    if (root == NULL)
//        return false;
//
//    if (isSameTree(root, subroot))
//        return true;
//
//    // 递归判断左右子树和root是否相等，其中一棵树与root相等，
//    // 整个结果都为true，所以这里是或的关系
//    return isSubtree(root->left, subroot) ||
//        isSubtree(root->right, subroot);
//}

//bool chkPalindrome(ListNode* A) {
//    // 如果A为空，或只有一个节点，则直接返回true
//    if (A == NULL || A->next == NULL)
//        return true;
//
//    ListNode* slow, * fast;
//    slow = fast = A;
//
//    // 1. 通过快慢指针的方法，找到链表中间节点
//    while (fast && fast->next)
//    {
//        // 慢指针走一步，快指针走两步
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//
//    // 2. 链表后半部分逆置，三指针的方式实现
//    ListNode* prev, * cur, * nxt;
//    prev = NULL;
//    cur = slow;
//
//    while (cur)
//    {
//        // 记录cur的下一个节点
//        nxt = cur->next;
//
//        // 实现反转，将cur的next指向prev前一个节点
//        cur->next = prev;
//
//        // 更新prev和cur，以此向后进行遍历反转
//        prev = cur;
//        cur = nxt;
//    }
//
//    // 3. 逐节点进行比对
//    while (A && prev)
//    {
//        // 如果两个节点值不相等，则直接返回false
//        if (A->val != prev->val)
//            return false;
//
//        // 更新指针，继续向后遍历
//        A = A->next;
//        prev = prev->next;
//    }
//
//    return true;
//}

void _MergeSort(int* arr, int begin, int end , int* tmp) {
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	//[begin mid] [mid + 1 , end]
	
	//处理左区间
	_MergeSort(arr, begin, mid, tmp);
	//处理右区间
	_MergeSort(arr, mid + 1, end, tmp);

	int begin1 = begin, begin2 = mid + 1;
	int end1 = mid, end2 = end;
	
	int i = begin;

	while (begin1 < end1 && begin2 < end2) {
		if (arr[begin1] <= arr[begin2])
			tmp[i++] = arr[begin1];
		else
			tmp[i++] = arr[begin2];
	}

	while (begin1 <= end1) {
		tmp[i++] = arr[begin1];
	}

	while (begin2 <= end2) {
		tmp[i++] = arr[begin2];
	}

	//将排序好的子区间拷贝回原数组
	for (int i = begin; i <= end;i++) {
		arr[i] = tmp[i];
	}
}

void MergeSort(int* arr, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);
	int begin = 0;
	int end = n - 1;
	_MergeSort(arr, begin , end , tmp);
	free(tmp);
}
