#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 哈夫曼树结点
typedef struct BinTNode {
    int weight;                  // 结点权值
    struct BinTNode* left;       // 左孩子
    struct BinTNode* right;      // 右孩子
} BTNode;

// 创建并初始化一个树结点
BTNode* BuyBTNode(int x) {
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));

    if (node == NULL) {
        perror("malloc fail");
        return NULL;
    }

    node->weight = x;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// 交换两个结点指针
// BTNode*& 是 C++ 的引用语法，因此该文件需要使用 .cpp 后缀
void Swap(BTNode*& x, BTNode*& y) {
    BTNode* tmp = x;
    x = y;
    y = tmp;
}

// 向下调整小堆
// a：存储树根结点指针的数组
// n：当前堆中有效元素的数量
// parent：需要向下调整的父结点下标
void AdjustDown(BTNode* a[], int n, int parent) {
    // 首先让 child 指向 parent 的左孩子
    int child = parent * 2 + 1;

    // child >= n 表示 parent 已经没有孩子
    while (child < n) {
        // 如果右孩子存在并且比左孩子小，则选择右孩子
        if (child + 1 < n &&
            a[child + 1]->weight < a[child]->weight) {
            ++child;
        }

        // 如果较小的孩子小于父结点，则交换二者
        if (a[child]->weight < a[parent]->weight) {
            Swap(a[child], a[parent]);

            // 继续从交换后的位置向下调整
            parent = child;
            child = parent * 2 + 1;
        }
        else {
            // 已经满足小堆性质
            break;
        }
    }
}

// 根据权值数组构造哈夫曼树
BTNode* CreateHuffmanTree(int a[], int n) {
    if (a == NULL || n <= 0) {
        return NULL;
    }

    // 使用小堆存储森林中的每棵树，便于取出权值最小的树
    // minHeap 是一个存储 BTNode* 的指针数组
    BTNode** minHeap =
        (BTNode**)malloc(sizeof(BTNode*) * n);

    if (minHeap == NULL) {
        perror("malloc fail");
        return NULL;
    }

    // 将每个权值分别构造成一棵仅包含一个结点的树
    for (int i = 0; i < n; ++i) {
        minHeap[i] = BuyBTNode(a[i]);

        if (minHeap[i] == NULL) {
            // 简化处理：实际项目中还应释放此前创建的结点
            free(minHeap);
            return NULL;
        }
    }

    // 从最后一个非叶子结点开始向下调整，建立小堆
    for (int i = (n - 2) / 2; i >= 0; --i) {
        AdjustDown(minHeap, n, i);
    }

    // 使用贪心算法构造哈夫曼树
    int heapSize = n;

    // 每次合并两棵树，森林中的树会减少一棵
    // 当只剩一棵树时，哈夫曼树构造完成
    while (heapSize > 1) {
        // 取出当前权值最小的树
        BTNode* rightChild = minHeap[0];

        // 使用最后一个元素覆盖堆顶，删除第一个最小结点
        minHeap[0] = minHeap[heapSize - 1];
        --heapSize;
        AdjustDown(minHeap, heapSize, 0);

        // 调整后，新的堆顶就是第二个最小结点
        BTNode* leftChild = minHeap[0];

        // 合并两棵权值最小的树
        BTNode* parent =
            BuyBTNode(leftChild->weight + rightChild->weight);

        if (parent == NULL) {
            // 简化处理：实际项目中还应释放已经构造的树
            free(minHeap);
            return NULL;
        }

        parent->left = leftChild;
        parent->right = rightChild;

        /*
         * 第二个最小结点位于堆顶，直接使用新结点替换它，
         * 相当于删除 leftChild 并插入 parent。
         * 新结点的权值一定不小于 leftChild，因此只需向下调整。
         */
        minHeap[0] = parent;
        AdjustDown(minHeap, heapSize, 0);
    }

    // 堆中最后剩下的结点就是哈夫曼树的根结点
    BTNode* root = minHeap[0];

    // 这里只释放小堆的指针数组，不释放树中的结点
    free(minHeap);

    return root;
}

// 递归计算哈夫曼树的带权路径长度（WPL）
// root：当前结点
// pathLen：当前结点到根结点的路径长度
// wpl：保存累计结果，使用引用传递
void HuffmanTreeWPL(BTNode* root, int pathLen, int& wpl) {
    // 空结点不参与计算
    if (root == NULL)
        return;

    // 叶子结点对 WPL 的贡献为：权值 × 路径长度
    if (root->left == NULL && root->right == NULL) {
        wpl += root->weight * pathLen;
        return;
    }

    // 递归遍历左右子树，子结点的路径长度加 1
    HuffmanTreeWPL(root->left, pathLen + 1, wpl);
    HuffmanTreeWPL(root->right, pathLen + 1, wpl);
}

void HuffmanCodeing(BTNode* root, char* str, int i) {
    if (root == NULL)
        return;

    // 叶子
    if (root->left == NULL && root->right == NULL) {
        str[i] = '\0';
        printf("%s\n", str);
        return;
    }

    str[i] = '0';
    HuffmanCodeing(root->left, str, i + 1);

    str[i] = '1';
    HuffmanCodeing(root->right, str, i + 1);
}

int main() {
    // 哈夫曼树中各叶子结点的权值
    int a[] = { 6, 3, 8, 2, 10, 4 };

    // 根据权值数组创建哈夫曼树
    BTNode* tree = CreateHuffmanTree(
        a, sizeof(a) / sizeof(int)
    );
    char code[100];
    //// 从根结点开始计算，根结点的路径长度为 0
    //int wpl = 0;
    //HuffmanTreeWPL(tree, 0, wpl);

    //// 输出哈夫曼树的带权路径长度
    //printf("%d\n", wpl);
    HuffmanCodeing(tree, code, 0);


    return 0;
}



