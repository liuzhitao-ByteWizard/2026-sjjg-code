#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>
#include <time.h>

//typedef int HeapDataType;
//
//void Swap(int* x, int* y)
//{
//    assert(x != NULL && y != NULL);
//
//    int tmp = *x;
//    *x = *y;
//    *y = tmp;
//}
//
//
//// 小堆的向下调整：从 parent 位置开始向下调整，恢复小堆结构。
//void AdjustDown(HeapDataType* a, int size, int parent)
//{
//    // 完全二叉树中，双亲下标为 parent 的左孩子下标为 parent * 2 + 1。
//    int child = parent * 2 + 1;
//
//    // child < size 说明当前双亲至少存在左孩子。
//    while (child < size)
//    {
//        // 若右孩子存在，并且右孩子比左孩子更小，（假设法）
//        // 则选择左右孩子中较小的那个与双亲比较。
//        if (child + 1 < size && a[child + 1] < a[child])
//        {
//            ++child;
//        }
//
//        // 小堆要求双亲结点不能大于孩子结点。
//        // 若较小的孩子仍比双亲小，则交换并继续向下调整。
//        if (a[child] < a[parent])
//        {
//            Swap(&a[child], &a[parent]);
//
//            // 交换后，原孩子位置成为新的双亲位置，
//            // 继续计算它的左孩子下标。
//            parent = child;
//            child = parent * 2 + 1;
//        }
//        else
//        {
//            // 双亲已经不大于较小的孩子，满足小堆性质。
//            break;
//        }
//    }
//}
//
//// 使用大堆进行升序排序
//void HeapSort(int* a, int len)
//{
//    // 从最后一个非叶子结点开始，依次向前执行向下调整
//    // 最后一个结点下标为 len - 1，其父结点下标为 (len - 2) / 2
//    // 调整完成后，整个数组构成一个大堆
//    for (int i = (len - 2) / 2; i >= 0; i--)
//    {
//        AdjustDown(a, len, i);
//    }
//
//    // j 表示当前正在选出第 j 大的元素
//    int j = 1;
//
//    while (j < len)
//    {
//        // 大堆的堆顶是当前最大值
//        // 将堆顶与当前堆区的最后一个元素交换
//        Swap(&a[0], &a[len - j]);
//
//        // 排除已经放到数组末尾的有序元素
//        // 对剩余的 len - j 个元素重新执行向下调整
//        AdjustDown(a, len - j, 0);
//
//        // 继续选出下一个较大的元素
//        j++;
//    }
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//// 创建包含大量随机数据的测试文件
//void CreateNDate()
//{
//    // 生成100万个随机数，用于测试Top-K算法
//    int n = 1000000;
//
//    // 使用当前时间设置随机数种子
//    // 每次运行程序时可以生成不同的数据
//    srand((unsigned int)time(NULL));
//
//    const char* file = "data.txt";
//
//    // 以写入方式打开文件
//    // 如果文件已经存在，则清空原有内容
//    FILE* fin = fopen(file, "w");
//    if (fin == NULL)
//    {
//        // 文件打开失败
//        perror("fopen error");
//        return;
//    }
//
//    // 生成n个0～999999之间的数据，并写入文件
//    for (int i = 0; i < n; i++)
//    {
//        int x = (rand() + i) % 1000000;
//        fprintf(fin, "%d\n", x);
//    }
//
//    // 关闭文件，释放文件资源
//    fclose(fin);
//}
//
//// 从大量数据中找出最大的前k个数据
//void topk()
//{
//    // 输入需要查找的数据个数k
//    printf("请输入k：>");
//
//    int k = 0;
//    scanf("%d", &k);
//
//    const char* file = "data.txt";
//
//    // 以只读方式打开测试数据文件
//    FILE* fout = fopen(file, "r");
//    if (fout == NULL)
//    {
//        // 文件打开失败
//        perror("fopen error");
//        return;
//    }
//
//    // 动态申请能够存放k个整数的空间
//    // 使用这k个位置建立小堆
//    int* minheap = (int*)malloc(sizeof(int) * k);
//    if (minheap == NULL)
//    {
//        // 内存申请失败
//        perror("malloc error");
//
//        // 释放已经打开的文件资源
//        fclose(fout);
//        return;
//    }
//
//    // 读取文件中的前k个数据，作为建堆的初始数据
//    for (int i = 0; i < k; i++)
//    {
//        fscanf(fout, "%d", &minheap[i]);
//    }
//
//    // 从最后一个非叶子结点开始向下调整
//    // 将前k个数据建立成小堆
//    for (int i = (k - 2) / 2; i >= 0; i--)
//    {
//        AdjustDown(minheap, k, i);
//    }
//
//    int x = 0;
//
//    // 继续读取文件中剩余的数据
//    while (fscanf(fout, "%d", &x) != EOF)
//    {
//        // 小堆的堆顶是当前k个数据中的最小值
//        // 如果新数据比堆顶大，说明它可能属于最大的前k个数据
//        if (x > minheap[0])
//        {
//            // 使用新数据替换堆顶
//            minheap[0] = x;
//
//            // 从根结点向下调整，重新维护小堆结构
//            AdjustDown(minheap, k, 0);
//        }
//    }
//
//    // 输出堆中保存的最大前k个数据
//    // 注意：堆只能保证父子关系，输出结果不一定有序
//    for (int i = 0; i < k; i++)
//    {
//        printf("%d ", minheap[i]);
//    }
//    printf("\n");
//
//    // 释放动态申请的内存
//    free(minheap);
//
//    // 关闭数据文件
//    fclose(fout);
//}
//
//int main() {
//    //CreateNDate();
//    topk();
//
//	return 0;
//}
//

typedef char BTDataType;

// 二叉链
typedef struct BinaryTreeNode
{
    struct BinaryTreeNode* left;   // 指向左孩子的指针
    struct BinaryTreeNode* right;  // 指向右孩子的指针
    BTDataType data;               // 数据元素
} BTNode;

// 创建一个二叉树结点
BTNode* BuyBTNode(int val)
{
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

    nodec->right = nodef;

    return nodea;
}

//前序遍历
void Preorder(BTNode* root) {
    if (root == NULL) {
        return;
    }

    printf("%c ", root->data);
    Preorder(root->left);
    Preorder(root->right);
  
}

void Inorder(BTNode* root) {
    if (root == NULL) {
        return;
    }
    Inorder(root->left);
    printf("%c ", root->data);
    Inorder(root->right);
}

void Postorder(BTNode* root) {
    if (root == NULL) {
        return;
    }

    Postorder(root->left);
    Postorder(root->right);
    printf("%c ", root->data);

}

int main()
{
    BTNode* root = CreateTree();

    Preorder(root);
    printf("\n");

    Inorder(root);
    printf("\n");

    Postorder(root);
    printf("\n");

    return 0;
}
