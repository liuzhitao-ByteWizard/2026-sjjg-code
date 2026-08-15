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

    //�ݹ�������
    _MergeSort(a, begin, mid, tmp);
    _MergeSort(a, mid + 1, end, tmp);

    //�����䣬���������򣬿�ʼ���еݹ�
    int begin1 = begin, begin2 = mid + 1;
    int end1 = mid, end2 = end;
    int i = begin; //����tmp����
    //������������䶼��Ϊ��
    while (begin1 <= end1 && begin2 <= end2) {
        if (a[begin1] <= a[begin2]) {
            tmp[i++] = a[begin1++];
        }
        else {
            tmp[i++] = a[begin2++];
        }
    }

    //��һ�������䲻Ϊ��ʱ������Ϊ�յ������俽����tmp������
    while (begin1 <= end1) {
        tmp[i++] = a[begin1++];
    }

    while (begin2 <= end2) {
        tmp[i++] = a[begin2++];
    }

    //��tmp���鿽����ԭ������
    for (int j = begin; j <= end; j++) {
        a[j] = tmp[j];
    }

}


void MergeSort(int* a, int n) {
    //������ʱ����
    int* tmp = (int*)malloc(sizeof(int) * n);
    if (tmp == NULL) {
        perror("malloc fail");
        return;
    }

    _MergeSort(a, 0, n - 1, tmp);

    free(tmp);
    tmp = NULL;
}

// �ȶ��ļ�������
void CountSort(int* a, int n)
{
    // ����Ϊ�ջ�Ԫ�ظ���С�ڵ��� 0 ʱ����������
    if (a == NULL || n <= 0)
        return;

    // ���������е���Сֵ�����ֵ
    int min = a[0];
    int max = a[0];

    for (int i = 1; i < n; ++i)
    {
        if (a[i] < min)
            min = a[i];

        if (a[i] > max)
            max = a[i];
    }

    // ����Ԫ�ص�ȡֵ��Χ
    // �� 1 ����Ϊ���� [min, max] Ϊ������
    int range = max - min + 1;

    // �����������飬��������Ԫ�س�ʼ��Ϊ 0
    // count[i] ��Ӧ��ʵ��Ԫ��ֵΪ i + min
    int* count = (int*)calloc(range, sizeof(int));
    if (count == NULL)
    {
        perror("calloc fail");
        return;
    }

    // ͳ��ÿ��Ԫ�س��ֵĴ���
    // ͨ����ȥ min����ʵ��Ԫ��ӳ�䵽�� 0 ��ʼ���±�
    for (int i = 0; i < n; ++i)
    {
        count[a[i] - min]++;
    }

    // �� count ����ת��Ϊǰ׺������
    // �����count[i] ��ʾС�ڻ���� i + min ��Ԫ�ظ���
    for (int i = 1; i < range; ++i)
    {
        count[i] += count[i - 1];
    }

    // ������ʱ���飬���ڱ���������
    int* tmp = (int*)malloc(sizeof(int) * n);
    if (tmp == NULL)
    {
        perror("malloc fail");
        free(count);
        return;
    }

    // �Ӻ���ǰ����ԭ���飬�Ա�֤������ȶ���
    for (int i = n - 1; i >= 0; --i)
    {
        // count[a[i] - min] ��ʾС�ڻ���� a[i] ��Ԫ�ظ���
        // �� 1 ��õ� a[i] ����ʱ�����е��±�
        int index = count[a[i] - min] - 1;
        tmp[index] = a[i];

        // ��ͬԪ���´�Ӧ��ŵ�ǰһ��λ��
        count[a[i] - min]--;
    }

    // �������Ľ�����ƻ�ԭ����
    for (int i = 0; i < n; ++i)
    {
        a[i] = tmp[i];
    }

    // �ͷŶ�̬������ڴ棬�����ڴ�й©
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
        // a1[i] = rand();  // �ظ����ݽ϶�

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
