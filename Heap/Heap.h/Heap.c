#include "Heap.h"


void Swap(int* x, int* y)
{
    assert(x != NULL && y != NULL);

    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void HeapInit(Heap* hp) {
    assert(hp);
    hp->a = NULL;
    hp->capacity = hp->size = 0;
}

void AdjustUp(HeapDataType* a, int child) {
    //计算双亲结点
    int parent = (child - 1) / 2;

    //孩子结点和双亲结点大小进行比较
    while (child > 0) {
        if (a[child] < a[parent]) {
            Swap(&a[child], &a[parent]);
            //之前的孩子结点变双亲结点
            child = parent;
            //计算下一个双亲结点
            parent = (child - 1) / 2;
        }
        else {
            //孩子结点不小于双亲结点，结束
            break;
        }
    }
}

void HeapPush(Heap* hp, HeapDataType x) {
    assert(hp);

    //扩容
    if (hp->size == hp->capacity) {
        //要判断堆的容量为0的情况
        int newcapacity = hp->capacity == 0 ? 4 : hp->capacity * 2;
        HeapDataType* tmp = (HeapDataType*)realloc(hp->a, sizeof(HeapDataType) * newcapacity);

        if (tmp == NULL) {
            perror("realloc fail");
            exit(-1);
        }

        //将成功动态开辟的数组空间,容量给原数组空间，tmp自动还给操作系统
        hp->a = tmp;
        hp->capacity = newcapacity;
    }
    //size记录的是有效元素末尾的下一个位置
    hp->a[hp->size++] = x;
    AdjustUp(hp->a, hp->size - 1);
}

// 小堆的向下调整：从 parent 位置开始向下调整，恢复小堆结构。
void AdjustDown(HeapDataType* a, int size, int parent)
{
    // 完全二叉树中，双亲下标为 parent 的左孩子下标为 parent * 2 + 1。
    int child = parent * 2 + 1;

    // child < size 说明当前双亲至少存在左孩子。
    while (child < size)
    {
        // 若右孩子存在，并且右孩子比左孩子更小，（假设法）
        // 则选择左右孩子中较小的那个与双亲比较。
        if (child + 1 < size && a[child + 1] < a[child])
        {
            ++child;
        }

        // 小堆要求双亲结点不能大于孩子结点。
        // 若较小的孩子仍比双亲小，则交换并继续向下调整。
        if (a[child] < a[parent])
        {
            Swap(&a[child], &a[parent]);

            // 交换后，原孩子位置成为新的双亲位置，
            // 继续计算它的左孩子下标。
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            // 双亲已经不大于较小的孩子，满足小堆性质。
            break;
        }
    }
}


// 堆的删除：删除堆顶元素。
// 对小堆而言，堆顶是最小值；对大堆而言，堆顶是最大值。
void HeapPop(Heap* hp)
{
    // 堆对象必须有效。
    assert(hp);

    // 空堆没有堆顶元素，不能删除。
    assert(hp->size > 0);

    // 先交换堆顶元素和堆尾元素。
    // 这样删除堆尾即可完成删除堆顶，避免整体前移数组元素。
    Swap(&hp->a[0], &hp->a[hp->size - 1]);

    // 堆尾元素原本的堆顶数据不再属于堆。
    --hp->size;

    // 交换后，左右子树仍保持堆结构，
    // 只有根结点可能不满足堆性质，因此从根开始向下调整。
    AdjustDown(hp->a, hp->size, 0);
}

int HeapEmpty(Heap* hp) {
    assert(hp);

    return hp->size == 0;
}

HeapDataType HeapTop(Heap* hp) {
    assert(hp);
    assert(!HeapEmpty(hp));

    return hp->a[0];
}