#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//#include <stdlib.h>
//
//typedef char BTDataType;
//
//// 二叉链
//typedef struct BinaryTreeNode
//{
//    struct BinaryTreeNode* left;   // 指向左孩子的指针
//    struct BinaryTreeNode* right;  // 指向右孩子的指针
//    BTDataType data;               // 数据元素
//} BTNode;
//
//// 创建一个二叉树结点
//BTNode* BuyBTNode(int val)
//{
//    BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
//    if (newnode == NULL)
//    {
//        perror("malloc fail");
//        return NULL;
//    }
//
//    newnode->data = val;
//    newnode->left = NULL;
//    newnode->right = NULL;
//
//    return newnode;
//}
//
//// 手动构造一棵二叉树
//BTNode* CreateTree()
//{
//    BTNode* nodea = BuyBTNode('a');
//    BTNode* nodeb = BuyBTNode('b');
//    BTNode* nodec = BuyBTNode('c');
//    BTNode* noded = BuyBTNode('d');
//    BTNode* nodee = BuyBTNode('e');
//    BTNode* nodef = BuyBTNode('f');
//
//    nodea->left = nodeb;
//    nodea->right = nodec;
//
//    nodeb->left = noded;
//    nodeb->right = nodee;
//
//    nodec->right = nodef;
//
//    return nodea;
//}
//
//// 按层打印二叉树：每一层的结点输出在同一行
//void Levelorder2(BTNode* root)
//{
//    // 动态申请一个可存放 100 个结点指针的队列
//    BTNode** queueArr = (BTNode**)malloc(sizeof(BTNode*) * 100);
//
//    // 判断内存是否申请成功
//    if (queueArr == NULL)
//    {
//        printf("malloc fail\n");
//        return;
//    }
//
//    // front 指向队首元素，rear 指向下一个可入队的位置
//    int front = 0;
//    int rear = 0;
//
//    // levelSize 表示当前层还有多少个结点等待访问
//    int levelSize = 0;
//
//    // 根结点非空时，先将根结点入队
//    if (root != NULL)
//    {
//        queueArr[rear++] = root;
//        levelSize = 1;  // 第一层只有根结点
//    }
//
//    // 队列不为空时，继续进行层序遍历
//    while (rear - front != 0)
//    {
//        // 依次处理当前层的 levelSize 个结点
//        while (levelSize--)
//        {
//            // 队首结点出队
//            BTNode* frontNode = queueArr[front++];
//
//            // 访问当前结点
//            printf("%c ", frontNode->data);
//
//            // 将当前结点的非空左孩子入队
//            if (frontNode->left)
//            {
//                queueArr[rear++] = frontNode->left;
//            }
//
//            // 将当前结点的非空右孩子入队
//            if (frontNode->right)
//            {
//                queueArr[rear++] = frontNode->right;
//            }
//        }
//
//        // 当前层访问结束，换行
//        printf("\n");
//
//        // 此时队列中剩余的结点全部属于下一层
//        levelSize = rear - front;
//    }
//
//    // 遍历结束后再换一行
//    printf("\n");
//
//    // 释放动态申请的队列空间
//    free(queueArr);
//    queueArr = NULL;
//}
//
//int main()
//{
//    BTNode* root = CreateTree();
//
//    //Preorder(root);
//    //printf("\n");
//
//    //Inorder(root);
//    //printf("\n");
//
//    //Postorder(root);
//    //printf("\n");
//
//    Levelorder2(root);
//
//    return 0;
//}
#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;

enum PointerTag {
    LINK = 0,
    THREAD = 1
};

// 二叉链
typedef struct BinaryTreeNode {
    struct BinaryTreeNode* left;   // 指向左孩子的指针
    struct BinaryTreeNode* right;  // 指向右孩子的指针
    BTDataType data;               // 数据元素
    PointerTag leftTag;            // 左标记
    PointerTag rightTag;           // 右标记
}BTNode;

BTNode* BuyBTNode(int val) {
    BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
    if (newnode == NULL) {
        perror("malloc fail");
        return NULL;
    }

    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->leftTag = LINK;
    newnode->rightTag = LINK;
    return newnode;
}

// 手动构造一棵二叉树
BTNode* CreateTree() {
    //      a
    //     / \
    //    b   d
    //   /     \
    //  c       e
    BTNode* nodea = BuyBTNode('a');
    BTNode* nodeb = BuyBTNode('b');
    BTNode* nodec = BuyBTNode('c');
    BTNode* noded = BuyBTNode('d');
    BTNode* nodee = BuyBTNode('e');

    nodea->left = nodeb;
    nodea->right = noded;

    nodeb->left = nodec;
    noded->right = nodee;

    return nodea;
}

// 对二叉树进行中序线索化。
// prev 始终指向当前结点 cur 在中序序列中的前驱结点。
void _InThread(BTNode* cur, BTNode*& prev) {
    // 递归终止条件：空结点无需处理。
    if (cur == NULL)
        return;

    // 先线索化左子树，保证访问 cur 时，prev 已指向 cur 的中序前驱。
    _InThread(cur->left, prev);

    // 若 cur 没有左孩子，则将左指针改为指向其中序前驱。
    if (cur->left == NULL) {
        cur->left = prev;
        cur->leftTag = THREAD;
    }

    // 若前驱结点存在且没有右孩子，
    // 则将其右指针改为指向当前结点 cur，建立后继线索。
    if (prev && prev->right == NULL) {
        prev->right = cur;
        prev->rightTag = THREAD;
    }

    // 当前结点处理完成后，它将成为后续结点的中序前驱。
    prev = cur;

    // 最后线索化右子树。
    _InThread(cur->right, prev);
}

// 对整棵二叉树进行中序线索化。
void InThreading(BTNode* root) {
    // 初始时没有中序前驱结点。
    BTNode* p = NULL;

    // 从根结点开始进行中序线索化。
    _InThread(root, p);

    //中序的最后一个结点需要线索化
    p->rightTag = THREAD;
}
void _PrevThread(BTNode* cur, BTNode*& prev) {
    if (cur == NULL)
        return;

    // cur左为空，线索化当前结点的左孩子
    if (cur->left == NULL) {
        cur->left = prev;
        cur->leftTag = THREAD;
    }

    // 最开始prev为空，所以需要先检查prev不为空
    // prev右为空，线索化上一个结点的右孩子
    if (prev && prev->right == NULL) {
        prev->right = cur;
        prev->rightTag = THREAD;
    }

    // 当前结点线索化完成后，相对于下一个前序结点，cur变成了上一个结点
    prev = cur;

    // 前序线索化，先线索化了当前结点，所以递归时要判断是LINK，才需要递归
    if (cur->leftTag == LINK)
        _PrevThread(cur->left, prev);

    if (cur->rightTag == LINK)
        _PrevThread(cur->right, prev);
}

// 前序线索化二叉树
void PrevThreading(BTNode* root) {
    BTNode* p = NULL;
    _PrevThread(root, p);

    //前序最后一个结点的右孩子需要线索化
    p->rightTag = THREAD;
}


void _PostThread(BTNode* cur, BTNode*& prev) {
    if (cur == NULL)
        return;

    // 后序线索化，先线索化了当前结点，所以递归时要判断是LINK，才需要递归
    _PostThread(cur->left, prev);
    _PostThread(cur->right, prev);

    // cur左为空，线索化当前结点的左孩子
    if (cur->left == NULL) {
        cur->left = prev;
        cur->leftTag = THREAD;
    }

    // 最开始prev为空，所以需要先检查prev不为空
    // prev右为空，线索化上一个结点的右孩子
    if (prev && prev->right == NULL) {
        prev->right = cur;
        prev->rightTag = THREAD;
    }

    // 当前结点线索化完成后，相对于下一个后序结点，cur变成了上一个结点
    prev = cur;
}

// 后序线索化二叉树
void PostThreading(BTNode* root) {
    BTNode* p = NULL;
    _PostThread(root, p);

    //后序最后一个结点的右孩子为空，需要线索化
    if (p->right == NULL)
        p->rightTag = THREAD;
}

// 获取中序线索二叉树中，以 root 为根的子树的第一个中序结点。
// 前提：root 不为空，且该二叉树已经完成中序线索化。
BTNode* InorderFirst(BTNode* root) {
    // 中序遍历顺序为“左子树 -> 根 -> 右子树”。
    // 只要左指针仍指向真实左孩子，就继续向左查找。
    while (root->leftTag == LINK)
        root = root->left;

    // 当前结点没有真实左孩子，其 leftTag 为 THREAD，
    // 因此它是该子树中序遍历的第一个结点。
    return root;
}

// 获取当前结点 cur 在中序序列中的后继结点。
// 前提：cur 不为空，且该二叉树已经完成中序线索化。
BTNode* InorderNext(BTNode* cur) {
    // 情况一：右指针是线索。
    // 此时右指针直接指向当前结点的中序后继。
    if (cur->rightTag == THREAD)
        return cur->right;

    // 情况二：右指针指向真实右孩子。
    // 当前结点的中序后继是其右子树中最靠左的结点。
    return InorderFirst(cur->right);
}

// 利用中序线索进行非递归中序遍历。
// 注意：该函数只负责遍历，不负责创建中序线索。
void InorderThread(BTNode* root) {
    // 空树不需要遍历。
    if (root) {
        // 首先找到整棵树中序遍历的第一个结点。
        BTNode* cur = InorderFirst(root);

        // 不断根据线索关系查找当前结点的中序后继。
        while (cur) {
            // 访问当前结点。
            printf("%c ", cur->data);

            // 移动到中序序列中的下一个结点。
            cur = InorderNext(cur);
        }
    }

    // 遍历结束后换行。
    printf("\n");
}
// 获取前序线索二叉树中当前结点 cur 的后继结点。
// 前提：cur 不为空，并且二叉树已经完成前序线索化。
BTNode* PreorderNext(BTNode* cur) {
    // 前序遍历顺序为“根 -> 左子树 -> 右子树”。

    // 若左指针指向真实左孩子，则左孩子就是前序后继。
    if (cur->leftTag == LINK)
        return cur->left;

    // 若没有真实左孩子，则下一个结点由右指针给出：
    // 1. rightTag == LINK 时，右指针指向真实右孩子；
    // 2. rightTag == THREAD 时，右指针指向前序后继。
    return cur->right;
}

// 利用前序线索对二叉树进行非递归前序遍历。
// 注意：该函数只负责遍历，不负责创建前序线索。
void PreorderThread(BTNode* root) {
    // 空树不需要遍历。
    if (root) {
        // 前序遍历的第一个结点就是根结点。
        BTNode* cur = root;

        // 不断通过线索或真实孩子指针查找前序后继。
        while (cur) {
            // 访问当前结点。
            printf("%c ", cur->data);

            // 移动到前序序列中的下一个结点。
            cur = PreorderNext(cur);
        }
    }

    // 遍历结束后换行。
    printf("\n");
}

// 获取后序线索二叉树中当前结点 cur 的前驱结点。
// 前提：cur 不为空，并且二叉树已经完成后序线索化。
BTNode* PostorderPrev(BTNode* cur) {
    // 后序遍历顺序为“左子树 -> 右子树 -> 根”。
    // 逆向后序遍历顺序为“根 -> 右子树 -> 左子树”。

    // 若右指针指向真实右孩子，则右孩子是当前结点
    // 在后序序列中的前一个结点。
    if (cur->rightTag == LINK)
        return cur->right;

    // 当前结点没有真实右孩子时：
    // 1. leftTag == LINK：左指针指向真实左孩子；
    // 2. leftTag == THREAD：左指针指向后序前驱。
    // 无论哪种情况，左指针都能得到下一个需要逆向访问的结点。
    return cur->left;
}

// 利用后序线索对二叉树进行非递归逆向后序遍历。
// 注意：该函数只负责遍历，不负责创建后序线索。
void RPostorderThread(BTNode* root) {
    // 空树不需要遍历。
    if (root) {
        // 后序遍历的最后一个结点是根结点，
        // 因此逆向后序遍历从根结点开始。
        BTNode* cur = root;

        // 不断查找当前结点在后序序列中的前驱。
        while (cur) {
            // 访问当前结点。
            printf("%c ", cur->data);

            // 移动到后序序列中的前一个结点。
            cur = PostorderPrev(cur);
        }
    }

    // 遍历结束后换行。
    printf("\n");
}


int main() {
    BTNode* root1 = CreateTree();
    InThreading(root1);
    InorderThread(root1);

    BTNode* root2 = CreateTree();
    PrevThreading(root2);
    PreorderThread(root2);

    BTNode* root3 = CreateTree();
    PostThreading(root3);
    RPostorderThread(root3);

    return 0;
}









BTNode* root3 = CreateTree();






























