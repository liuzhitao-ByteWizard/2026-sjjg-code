#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

void Swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void PrintArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
}

// 对长度为 n 的整型数组 a 进行升序选择排序
void SelectSort(int* a, int n)
{
    // 依次确定第 j 个位置应放置的最小元素
    for (int j = 0; j < n - 1; j++)
    {
        // 假设待排序区间的第一个元素最小
        int mini = j;

        // 在 [j + 1, n - 1] 中查找真正的最小元素下标
        for (int i = j + 1; i < n; i++)
        {
            if (a[i] < a[mini])
            {
                mini = i;
            }
        }

        // 将最小元素交换到第 j 个位置
        Swap(&a[mini], &a[j]);
    }
}

void TestSelectSort()
{
    int a[] = { 9, 1, 2, 5, 7, 4, 6, 3 };

    PrintArray(a, sizeof(a) / sizeof(int));
    SelectSort(a, sizeof(a) / sizeof(int));
    PrintArray(a, sizeof(a) / sizeof(int));
}

//void Swap(int* x, int* y) {
//    int tmp = *x;
//    *x = *y;
//    *y = tmp;
//}

//向下调整算法
void AdjustDown(int* a, int n, int parent) {
    // 假设法逻辑，child先指向左孩子
    int child = parent * 2 + 1;

    // child >= n超出数组的范围，说明孩子不存在，
    // parent指向叶子结点，调整到叶子结束
    while (child < n) {
        // 左孩子跟右孩子比较，找出大的那个孩子
        if (child + 1 < n && a[child + 1] > a[child]) {
            ++child;
        }

        // 孩子大于父亲，将大的孩子调整到父亲位置
        if (a[child] > a[parent]) {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else {
            break;
        }
    }
}

// O(N*logN)
void HeapSort(int* a, int n) {
    // 建堆 O(N)
    // 升序，建大堆
    // 降序，建小堆
    for (int i = (n - 1 - 1) / 2; i >= 0; --i) {
        AdjustDown(a, n, i);
    }

    // O(N*logN)
    int j = 1;
    while (j < n) {
        // 选出的第j大/小的数据换到倒数第j个位置
        Swap(&a[0], &a[n - j]);
        AdjustDown(a, n - j, 0);
        ++j;
    }
}

// 冒泡排序：将数组按升序排列
void BubbleSort(int* a, int n) {
    // 最多进行 n - 1 趟冒泡
    // 每完成一趟，当前未排序区间的最大元素都会移动到末尾
    for (int j = 0; j < n - 1; j++) {
        // 标记本趟是否发生过元素交换
        int flag = 0;

        // 两两比较未排序区间中的相邻元素
        // 后面的 j 个元素已经有序，无需再次比较
        for (int i = 1; i < n - j; i++) {
            // 如果前一个元素大于后一个元素，则交换二者
            if (a[i - 1] > a[i]) {
                Swap(&a[i - 1], &a[i]);
                flag = 1;
            }
        }

        // 本趟没有发生交换，说明数组已经有序，可以提前结束
        if (flag == 0) {
            break;
        }
    }
}

void QuickSort(int* a, int left, int right) {
    if (left >= right)
        return;

    //存储的是基准值的下标
    int pivotkeyi = PartitionLomuto(a, left, right);
    QuickSort(a, left, pivotkeyi - 1);
    QuickSort(a, pivotkeyi + 1, right);

}

// 挖坑法划分：对数组 a 的 [left, right] 区间进行一次划分
// 返回基准值完成划分后的最终下标
int PartitionDigHole(int* a, int left, int right) {
    // 选取区间最左侧元素作为基准值
    // 此时 left 所在位置可以看作第一个“坑”
    int pivokey = a[left];

    // 当 left 与 right 相遇时，划分结束
    while (left < right) {
        // 从右向左寻找小于基准值的元素
        while (left < right && a[right] >= pivokey) {
            right--;
        }

        // 将找到的较小元素填入左侧的坑
        // 此时 right 所在位置形成新的坑
        a[left] = a[right];

        // 从左向右寻找大于基准值的元素
        while (left < right && a[left] <= pivokey) {
            left++;
        }

        // 将找到的较大元素填入右侧的坑
        // 此时 left 所在位置重新形成坑
        a[right] = a[left];
    }

    // left 与 right 相遇，将基准值填入最后的坑
    // a[right] = pivokey;
    a[left] = pivokey;

    // 返回基准值最终所在的位置
    return left;
}

// Lomuto 单趟划分：对数组 a 的 [left, right] 区间进行划分
// 返回基准值完成划分后的最终下标
int PartitionLomuto(int* a, int left, int right) {
    // 选取区间最右侧的元素作为基准值
    int pivoti = right;

    // prev 指向“小于等于基准值”区间的末尾
    int prev = left - 1;

    // cur 用于遍历基准值前面的所有元素
    int cur = left;

    while (cur < right) {
        // 当前元素小于等于基准值时，扩大小值区间
        // 如果 prev 与 cur 不重合，则交换这两个位置的元素
        if (a[cur] <= a[pivoti] && ++prev != cur) {
            Swap(&a[prev], &a[cur]);
        }

        // 继续检查下一个元素
        ++cur;
    }

    // 将基准值交换到大小区间的分界位置
    Swap(&a[++prev], &a[pivoti]);

    // 返回基准值的最终下标
    return prev;
}


void TestHeapSort() {
    int a[] = { 9,1,2,5,7,4,6,3 };

    PrintArray(a, sizeof(a) / sizeof(int));
    HeapSort(a, sizeof(a) / sizeof(int));
    PrintArray(a, sizeof(a) / sizeof(int));
}

void TestBubbleSort()
{
    int a[] = { 9, 1, 2, 5, 7, 4, 6, 3 };

    PrintArray(a, sizeof(a) / sizeof(int));
    BubbleSort(a, sizeof(a) / sizeof(int));
    PrintArray(a, sizeof(a) / sizeof(int));
}

void TestPerformance() {
    srand(time(0));
    const int N = 100000;

    int* a1 = (int*)malloc(sizeof(int) * N);
    int* a2 = (int*)malloc(sizeof(int) * N);
    int* a3 = (int*)malloc(sizeof(int) * N);
    int* a4 = (int*)malloc(sizeof(int) * N);
    int* a5 = (int*)malloc(sizeof(int) * N);
    int* a6 = (int*)malloc(sizeof(int) * N);
    int* a7 = (int*)malloc(sizeof(int) * N);
    int* a8 = (int*)malloc(sizeof(int) * N);
    int* a9 = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; ++i) {
        a1[i] = rand() + i;
        // a1[i] = rand();  // 重复数据较多

        a2[i] = a1[i];
        a3[i] = a1[i];
        a4[i] = a1[i];
        a5[i] = a1[i];
        a6[i] = a1[i];
        a7[i] = a1[i];
        a8[i] = a1[i];
        a9[i] = a1[i];
    }

    int begin1 = clock();
    // InsertSort(a1, N);
    int end1 = clock();

    int begin2 = clock();
    // ShellSort(a2, N);
    int end2 = clock();

    int begin3 = clock();
     SelectSort(a3, N);
    int end3 = clock();

    int begin4 = clock();
     HeapSort(a4, N);
    int end4 = clock();

    int begin5 = clock();
    BubbleSort(a5, N);
    int end5 = clock();

    int begin6 = clock();
    QuickSort(a6, 0, N - 1);
    int end6 = clock();

    int begin7 = clock();
    // MergeSort(a7, N);
    int end7 = clock();

    int begin8 = clock();
    // CountSort(a8, N);
    int end8 = clock();

    int begin9 = clock();
    // RadixSortLSD(a9, N);
    int end9 = clock();

    printf("InsertSort:%d\n", end1 - begin1);
    printf("ShellSort:%d\n", end2 - begin2);
    printf("SelectSort:%d\n", end3 - begin3);
    printf("HeapSort:%d\n", end4 - begin4);
    printf("BubbleSort:%d\n", end5 - begin5);
    printf("QuickSort:%d\n", end6 - begin6);
    printf("MergeSort:%d\n", end7 - begin7);
    printf("CountSort:%d\n", end8 - begin8);
    printf("RadixSortLSD:%d\n", end9 - begin9);

    free(a1);
    free(a2);
    free(a3);
    free(a4);
    free(a5);
    free(a6);
    free(a7);
    free(a8);
    free(a9);
}

// hoare 左右指针
int PartitionHoare(int* a, int left, int right) {
    int pivotkey = a[left]; // 选择第一个元素作为pivotkey
    int low = left - 1;
    int high = right + 1;

    while (true) {
        // 从左向右找第一个 >= pivotkey 的元素
        do {
            low++;
        } while (a[low] < pivotkey);

        // 从右向左找第一个 <= pivotkey 的元素
        do {
            high--;
        } while (a[high] > pivotkey);

        // 如果相遇或交叉,返回high
        if (low >= high)
            return high;

        // 把小的换到左边,大的换到右边
        Swap(&a[low], &a[high]);
    }
}

void QuickSortHoare(int* a, int left, int right) {
    if (left >= right)
        return;

    int pivoti = PartitionHoare(a, left, right);

    // 序列被分割为[left,pivoti]和[pivoti+1,right], [left,pivoti]的值小于等于pivotkey,
    // [pivoti+1,right]大于等于pivotkey, Hoare法单趟分割并没有确定pivotkey作为主元分割区间
    // 所以递归时,一定要注意左区间包含分割点pivoti,这点跟挖坑法和Lomuto法是不一样的,一定要注意
    // [left, pivoti] [pivoti+1, right]
    QuickSortHoare(a, left, pivoti);
    QuickSortHoare(a, pivoti + 1, right);
}

void TestQuickSort() {
    int a[] = { 23,44,38,5,47,15,36,26,23,2 };

    PrintArray(a, sizeof(a) / sizeof(int));
    QuickSortHoare(a, 0, sizeof(a) / sizeof(int) - 1);
    PrintArray(a, sizeof(a) / sizeof(int));
}

int main() {
    //TestSelectSort();
    //TestHeapSort();
    //TestPerformance();
    //TestBubbleSort();
    TestQuickSort();
    return 0;
}