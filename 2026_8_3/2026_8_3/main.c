#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>  
//
//typedef struct TreeNode {
//    char val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//}BSTNode;
//
//BSTNode* buildTree(char* arr, int* i) {
//    //申请结点
//    if (arr[*i] == '#') {
//        (*i)++;
//        return NULL;
//    }
//    BSTNode* Node = (BSTNode*)malloc(sizeof(BSTNode));
//    Node->val = arr[(*i)++];
//    
//
//    Node->left = buildTree(arr, i);
//    Node->right = buildTree(arr, i);
//
//    return Node;
//}
//
//void inorder(BSTNode* root) {
//    if (root == NULL)
//        return;
//
//    inorder(root->left);
//    printf("%c ", root->val);
//    inorder(root->right);
//}
//
//int main() {
//    int i = 0; //遍历字符串
//    char arr[100];
//    scanf("%s", arr);
//
//    //构建树
//    BSTNode* root = buildTree(arr, &i);
//
//    //进行中序遍历
//    inorder(root);
//
//    return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct TreeNode {
//    struct TreeNode* left;
//    struct TreeNode* right;
//    char val;
//} Node;
//
//Node* buildTree(char* arr, int* pi) {
//    if (arr[*pi] == '#') {
//        (*pi)++;
//        return NULL;
//    }
//
//    Node* node = (Node*)malloc(sizeof(Node));
//    node->val = arr[*pi];
//    (*pi)++;
//
//    node->left = buildTree(arr, pi);
//    node->right = buildTree(arr, pi);
//
//    return node;
//}
//
//void Inorder(Node* root) {
//    if (root == NULL)
//        return;
//
//    Inorder(root->left);
//    printf("%c ", root->val);
//    Inorder(root->right);
//}
//
//int main() {
//    char arr[100];
//    scanf("%s", arr);
//
//    int i = 0;
//    Node* root = buildTree(arr, &i);
//
//    Inorder(root);
//    printf("\n");
//
//    return 0;
//}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef char BTDataType;

typedef struct BinaryTreeNode {
    struct BinaryTreeNode* left;   // 指向左孩子的指针
    struct BinaryTreeNode* right;  // 指向右孩子的指针
    BTDataType data;               // 数据元素
}BTNode;

BTNode* BuyBTNode(int val) {
    BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
    if (newnode == NULL)
    {
        perror("malloc fail");
        return NULL;
    }
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// 实现前中后续遍历，重点画递归展开执行过程，理解执行过程
void Preorder(BTNode* root) {
    if (root == NULL) {
        printf("N ");
        return;
    }

    // 根    
    printf("%c ", root->data);
    // 递归遍历左子树
    Preorder(root->left);
    // 递归遍历右子树
    Preorder(root->right);
}

// 手动构造一棵二叉树
BTNode* CreateTree()
{
    BTNode* nodea = BuyBTNode('a');
    BTNode* nodeb = BuyBTNode('b');
    BTNode* nodec = BuyBTNode('c');
    BTNode* noded = BuyBTNode('d');
    BTNode* nodee = BuyBTNode('e');
    BTNode* nodef = BuyBTNode('f');

    nodea->left = nodeb;
    nodea->right = nodec;

    nodeb->left = noded;
    nodeb->right = nodee;

    nodec->right = NULL;
    nodec->left = nodef;

    noded->right = NULL;
    noded->left = NULL;

    nodee->right = NULL;
    nodee->left = NULL;

    nodef->right = NULL;
    nodef->left = NULL;
    return nodea;
}

// 层序遍历二叉树
//// 核心思路：使用队列保存等待访问的结点
//void Levelorder1(BTNode* root)
//{
//    //方法一：使用数组模拟队列，数组中保存的是结点指针（开大一点的数组，忽略假溢出的问题）
//    BTNode* queueArr[100];
//
//    //方法二：用malloc动态开辟，注意要使用二级指针
//    // 动态申请一个能够保存 100 个结点指针的队列
//    // queueArr 的类型为 BTNode**，本质上是一个结点指针数组
//    //BTNode** queueArr =
//    //    (BTNode**)malloc(sizeof(BTNode*) * 100);
//
//    // //检查动态内存是否申请成功
//    //if (queueArr == NULL)
//    //{
//    //    printf("malloc fail\n");
//    //    return;
//    //}
//
//
//    // front 指向当前队首结点
//    // rear 指向下一个可以入队的位置
//    int front = 0;
//    int rear = 0;
//
//    // 如果根结点不为空，先将根结点入队
//    if (root)
//    {
//        queueArr[rear++] = root;
//    }
//
//    // front != rear 表示队列不为空
//    while (front != rear)
//    {
//        // 取出队首结点
//        BTNode* frontNode = queueArr[front];
//
//
//        // front 后移，表示队首结点出队
//        ++front;
//
//        if (frontNode)
//            printf("%c ", frontNode->data);
//
//        // 左孩子不为空，将左孩子入队
//        if (frontNode && frontNode->left)
//        {
//            queueArr[rear++] = frontNode->left;
//        }
//
//        // 右孩子不为空，将右孩子入队
//        if (frontNode && frontNode->right)
//        {
//            queueArr[rear++] = frontNode->right;
//        }
//    }
//
//    // 层序遍历结束后换行
//    printf("\n");
//}

void Levelorder1(BTNode* root) {
    BTNode* queueArr[100];

    int front = 0;
    int rear = 0; //指向队列末尾的下一个位置
    int leverSize = 1; //当前遍历层数

    if (root) {
        queueArr[rear++] = root;
    }

    while (rear - front != 0) {
        while (leverSize--) {
            BTNode* frontNode = queueArr[front++];
            if (frontNode)
                printf("%c ", frontNode->data);

            //取左右孩子入队
            if (frontNode->left)
                queueArr[rear++] = frontNode->left;
            if (frontNode->right)
                queueArr[rear++] = frontNode->right;
        }
        printf("\n");
        leverSize = rear - front;
    }
}

int main() {
    BTNode* root = CreateTree();

    //Preorder(root);
    //printf("\n");

    Levelorder1(root);
}
