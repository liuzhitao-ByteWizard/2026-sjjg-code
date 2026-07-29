#include "1.h"

//建小堆
void HeapInitArray(Heap* hp, HeapDataType* a, int n) {
    assert(hp != NULL && a != NULL);
    hp->a = (HeapDataType*)malloc(sizeof(HeapDataType) * n);

    for (int i = 0; i < n; i++) {
        hp->a[i] = a[i];
    }

    if (hp->a == NULL) {
        perror("malloc fail");
        exit(-1);
    }

    hp->size = hp->capacity = n;

    //执行向下调整算法
    for (int i = (hp->size - 1 - 1) / 2; i >= 0; i--) {
        AdjustDown(hp, n, i);
    }

    //top-k问题
    int k = 0;
    scanf("%d", &k);

    //升序：堆排序（大堆）
    while (k-- ) {
        HeapDataType tmp = hp->a[0];
        printf("%d ", tmp);

        //执行删除操作
        Swap(&hp->a[0], &hp->a[n - 1]);
        hp->size--;

        AdjustDown(hp, hp->size, 0);
    }
}

void HeapSort(int* a, int n) {

}


