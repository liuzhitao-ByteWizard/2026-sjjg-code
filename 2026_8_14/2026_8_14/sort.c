#define _CRT_SECURE_NO_WARNINGS

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

void _MergeSort(int* a, int begin , int end, int* tmp) {
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;

    //递归左区间
    _MergeSort(a, begin, mid, tmp);
    _MergeSort(a, mid + 1, end, tmp);

    //左区间，右区间有序，开始进行递归
    int begin1 = begin, begin2 = mid + 1;
    int end1 = mid, end2 = end;
    int i = begin; //控制tmp数组
    //左区间和右区间都不为空
    while (begin1 <= end1 && begin2 <= end2) {
        if (a[begin1] <= a[begin2]) {
            tmp[i++] = a[begin1++];
        }
        else {
            tmp[i++] = a[begin2++];
        }
    }

    //有一个子区间不为空时，将不为空的子区间拷贝到tmp数组上
    while (begin1 <= end1) {
        tmp[i++] = a[begin1++];
    }

    while (begin2 <= end2) {
        tmp[i++] = a[begin2++];
    }

    //将tmp数组拷贝到原数组中
    for (int j = begin; j <= end; j++) {
        a[j] = tmp[j];
    }

}


void MergeSort(int* a, int n) {
    //创建临时数组
    int* tmp = (int*)malloc(sizeof(int) * n);
    if (tmp == NULL) {
        perror("malloc fail");
        return;
    }

    _MergeSort(a, 0, n - 1, tmp);

    free(tmp);
    tmp = NULL;
}

// 稳定的计数排序
void CountSort(int* a, int n)
{
    // 数组为空或元素个数小于等于 0 时，无需排序
    if (a == NULL || n <= 0)
        return;

    // 查找数组中的最小值和最大值
    int min = a[0];
    int max = a[0];

    for (int i = 1; i < n; ++i)
    {
        if (a[i] < min)
            min = a[i];

        if (a[i] > max)
            max = a[i];
    }

    // 计算元素的取值范围
    // 加 1 是因为区间 [min, max] 为闭区间
    int range = max - min + 1;

    // 创建计数数组，并将所有元素初始化为 0
    // count[i] 对应的实际元素值为 i + min
    int* count = (int*)calloc(range, sizeof(int));
    if (count == NULL)
    {
        perror("calloc fail");
        return;
    }

    // 统计每个元素出现的次数
    // 通过减去 min，将实际元素映射到从 0 开始的下标
    for (int i = 0; i < n; ++i)
    {
        count[a[i] - min]++;
    }

    // 将 count 数组转换为前缀和数组
    // 处理后，count[i] 表示小于或等于 i + min 的元素个数
    for (int i = 1; i < range; ++i)
    {
        count[i] += count[i - 1];
    }

    // 创建临时数组，用于保存排序结果
    int* tmp = (int*)malloc(sizeof(int) * n);
    if (tmp == NULL)
    {
        perror("malloc fail");
        free(count);
        return;
    }

    // 从后向前遍历原数组，以保证排序的稳定性
    for (int i = n - 1; i >= 0; --i)
    {
        // count[a[i] - min] 表示小于或等于 a[i] 的元素个数
        // 减 1 后得到 a[i] 在临时数组中的下标
        int index = count[a[i] - min] - 1;
        tmp[index] = a[i];

        // 相同元素下次应存放到前一个位置
        count[a[i] - min]--;
    }

    // 将排序后的结果复制回原数组
    for (int i = 0; i < n; ++i)
    {
        a[i] = tmp[i];
    }

    // 释放动态申请的内存，避免内存泄漏
    free(count);
    free(tmp);
}

void TestMergeSort()
{
    int a[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8, 11 };
    // int a[] = { 10, 6, 7, 1, 3, 9, 4, 2 };

    PrintArray(a, sizeof(a) / sizeof(int));
    MergeSort(a, sizeof(a) / sizeof(int));
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
    //SelectSort(a3, N);
    int end3 = clock();

    int begin4 = clock();
    //HeapSort(a4, N);
    int end4 = clock();

    int begin5 = clock();
    //BubbleSort(a5, N);
    int end5 = clock();

    int begin6 = clock();
    //QuickSort(a6, 0, N - 1);
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

void TestCountSort()
{
     //int a[] = { 14, 19, 13, 10, 19, 14, 19, 18 };
    int a[] = { 6, 1, 2, 9, 4, 2, 4, 1, 4, -5, -5, -3, 6 };

    PrintArray(a, sizeof(a) / sizeof(int));
    CountSort(a, sizeof(a) / sizeof(int));
    PrintArray(a, sizeof(a) / sizeof(int));
}



int main() {
    TestCountSort();
    // TestMergeSort();
    return 0;
}
