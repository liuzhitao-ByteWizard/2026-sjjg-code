#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef char UFSDataType;

typedef struct {
    UFSDataType data;
    int parent;
} ufsNode;

ufsNode ufs[10];

// 查找元素 x 所属集合（树）的根结点下标
// ufsParent[i] < 0 表示 i 是根结点；否则其值为父结点的下标
int Find(int* ufsParent, int x) {
    // 沿双亲指针不断向上查找，直到找到根结点
    while (ufsParent[x] >= 0) {
        x = ufsParent[x];
    }

    // 返回根结点的下标
    return x;
}

// 查找元素 x 所属集合的根结点
int FindOP(int* ufsParent, int x) {
    // parent 值非负，表示当前结点不是根结点，
    // 其值为父结点的下标
    int root = x;
    while (ufsParent[root] >= 0) {
        root = ufsParent[root];
    }

    //路径压缩（将除根节点之外的结点链接到根节点的下方）
    while (root != x) {
        int next = ufsParent[x];
        ufsParent[x] = root;
        x = next;
    }

    // 返回根结点下标
    return x;
}



// 合并元素 x1 和 x2 所在的两个集合
void Union(int* ufs, int x1, int x2) {
    // 分别查找 x1 和 x2 所在树的根结点
    int root1 = FindOP(ufs, x1);
    int root2 = FindOP(ufs, x2);

    // 根结点不同，说明两个元素属于不同集合，需要进行合并
    if (root1 != root2) {
        // 根结点的负值表示集合中的元素数量，合并后更新集合大小
        ufs[root1] += ufs[root2];

        // 将 root2 指向 root1，使 root2 所在的树合并到 root1 所在的树中
        ufs[root2] = root1;
    }
}


//
//int findCircleNum(
//    int** isConnected,
//    int isConnectedSize,
//    int* isConnectedColSize
//) {
//    // 初始化并查集：每个城市单独构成一个集合
//    // 根结点的负值表示该集合包含的城市数量
//    int ufsParent[isConnectedSize];
//
//    for (int i = 0; i < isConnectedSize; ++i) {
//        ufsParent[i] = -1;
//    }
//
//    // 遍历城市连接矩阵
//    for (int i = 0; i < isConnectedSize; ++i) {
//        for (int j = 0; j < isConnectedColSize[i]; ++j) {
//            // 跳过城市自身；若城市 i 和城市 j 直接相连，则合并两个集合
//            if (i != j && isConnected[i][j] == 1) {
//                // 查找两个城市所属集合的根结点
//                int root1 = Find(ufsParent, i);
//                int root2 = Find(ufsParent, j);
//
//                // 根结点不同，说明两个城市尚未处于同一个集合
//                if (root1 != root2) {
//                    // 更新合并后集合的城市数量
//                    ufsParent[root1] += ufsParent[root2];
//
//                    // 将 root2 所在的树合并到 root1 所在的树
//                    ufsParent[root2] = root1;
//                }
//            }
//        }
//    }
//
//    // 统计根结点数量，即统计省份数量
//    int count = 0;
//
//    for (int i = 0; i < isConnectedSize; ++i) {
//        // parent 值为负数，表示该结点是某棵树的根结点
//        if (ufsParent[i] < 0) {
//            ++count;
//        }
//    }
//
//    return count;
//}


int main() {
    // 我们可以把元素和双亲下标存储在结构体中，定义一个结构体数组
    // 也可以像下面这样，分开存储在两个数组中
    char a[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };

    // 双亲表示法的森林
    // union find set
    int ufs[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

    Union(ufs, 0, 1);
    Union(ufs, 0, 2);
    Union(ufs, 0, 3);

    Union(ufs, 4, 5);
    Union(ufs, 9, 4);

    Union(ufs, 6, 7);
    Union(ufs, 8, 9);
    Union(ufs, 6, 8);

    // 测试路径压缩
    FindOP(ufs, 4);

    return 0;
}
