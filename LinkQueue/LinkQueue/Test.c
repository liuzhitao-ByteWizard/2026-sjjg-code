#define _CRT_SECURE_NO_WARNINGS

// test.c
#include "LinkQueue.h"

int main() {
    LinkQueue lq;
    QueueInit(&lq);

    EnQueue(&lq, 1);
    EnQueue(&lq, 2);
    EnQueue(&lq, 3);
    EnQueue(&lq, 4);

    printf("队列数据个数%d\n", QueueSize(&lq));
    printf("出队%d\n", DeQueue(&lq));
    printf("出队%d\n", DeQueue(&lq));

    EnQueue(&lq, 5);
    EnQueue(&lq, 6);

    printf("出队%d\n", DeQueue(&lq));
    printf("出队%d\n", DeQueue(&lq));
    printf("队列数据个数%d\n", QueueSize(&lq));

    printf("出队%d\n", DeQueue(&lq));
    printf("出队%d\n", DeQueue(&lq));

     //printf("出队%d\n", DeQueue(&lq));

    QueueDestroy(&lq);

    return 0;
}