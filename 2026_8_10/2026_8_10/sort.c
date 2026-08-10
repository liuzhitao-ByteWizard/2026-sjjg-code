#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 直接插入排序：将每个元素插入到前面已经排好序的区间中
void InsertSort(int* a, int n) {
    // 每轮将 a[i + 1] 插入已有序区间 a[0, i]
    for (int i = 0; i < n - 1; i++) {
        int end = i;  // 当前有序区间的最后一个下标

        // 此时 a[0, end] 有序，暂存待插入元素，防止后移时被覆盖
        int tmp = a[end + 1];

        // 从有序区间末尾向前比较，寻找 tmp 的插入位置
        while (end >= 0) {
            // 比 tmp 大的元素依次后移；相等元素不移动，保证排序稳定性
            if (tmp < a[end]) {
                a[end + 1] = a[end];
                --end;
            }
            else {
                break;  // 找到 tmp 的正确插入位置
            }
        }

        // 将 tmp 插入空出的位置
        a[end + 1] = tmp;
    }
}

//void ShellSort(int* a, int n) {
//    int d = n;  // 初始增量
//
//    // 按 Knuth 增量序列不断缩小间隔，d == 1 时即为直接插入排序
//    while (d > 1) {
//        d = d / 3 + 1;
//
//        // 按当前增量 d 划分为 d 组：j、j+d、j+2d……
//        for (int j = 0; j < d; j++) {
//            // 对第 j 组执行插入排序
//            for (int i = j; i < n - d; i += d) {
//                int end = i;           // 当前分组已有序区间的末尾下标
//                int tmp = a[end + d];  // 暂存待插入元素
//
//                // 沿当前分组从后向前比较，寻找 tmp 的插入位置
//                while (end >= j) {
//                    if (a[end] > tmp) {
//                        a[end + d] = a[end];  // 较大元素向后移动一个增量位置
//                        end -= d;             // 比较当前分组的前一个元素
//                    }
//                    else {
//                        break;  // 找到正确插入位置
//                    }
//                }
//
//                // 将待插入元素放入空出的位置
//                a[end + d] = tmp;
//            }
//        }
//    }
//}

void ShellSort(int* a, int n) {
    int d = n;  // 当前增量（分组间隔）

    // 不断缩小增量；当 d == 1 时，最后一轮相当于直接插入排序
    while (d > 1) {
        d = d / 3 + 1;  // 按 1/3 规则缩小增量
        // d = d / 2;   // 另一种常见的增量缩小方式

        // 依次处理各个间隔为 d 的子序列
        for (int i = 0; i < n - d; i++) {
            int end = i;
            int tmp = a[end + d];

            while (end >= 0) {
                if (tmp < a[end]) {
                    a[end + d] = a[end];
                    end -= d;
                }
                else {
                    break;
                }
            }
            a[end + d] = tmp;
        }
    }
}

void PrintArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	printf("\n");
}

void TestInsertSort() {
	int a[] = { 2, 4, 1, 7, 8, 3, 9, 2 };

	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));

}

void TestShellSort() {
    int a[] = { 2, 4, 1, 7, 8, 3, 9, 2 };

    ShellSort(a, sizeof(a) / sizeof(int));
    PrintArray(a, sizeof(a) / sizeof(int));

}

int main() {
	//TestInsertSort();
    TestShellSort();
}