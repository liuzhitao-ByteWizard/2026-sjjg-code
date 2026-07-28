#include "Heap.h"

// main.c
void TestHeap1()
{
    int a[] = { 4, 2, 8, 1, 5, 6, 9, 7, 3, 2 };

    Heap h;
    HeapInit(&h);

    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        HeapPush(&h, a[i]);
    }

    // HeapInitArray(&h, a, sizeof(a) / sizeof(int));

    // 堆并不代表有序，但是持续出堆顶的数据，就打印出有序序列
    // int i = 0;
    int k;
    scanf("%d", &k);

    while (!HeapEmpty(&h) && k--)
    {
        // int x = HeapEmpty(&h);
        printf("%d ", HeapTop(&h));
        // a[i++] = HeapTop(&h);
        HeapPop(&h);
    }

    printf("\n");

    HeapDestroy(&h);
}

int main()
{
    TestHeap1();

    return 0;
}
