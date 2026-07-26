#define _CRT_SECURE_NO_WARNINGS
#include "LinkQueue.h"

//带头结点初始化
void QueueInit(LinkQueue* q) {
	assert(q);
	q->front = q->rear = (QNode*)malloc(sizeof(QNode));
	if (q->front == NULL) {
		perror("malloc fail");
		exit(-1);
	}
	q->front->next = NULL;
	q->size = 0;
}

void QueueDestroy(LinkQueue* q) {
	assert(q);
	//assert(!QueueEmpty(q)); 注意：由于我们创建的队列结构中有头结点，所以不需要判空

	// 从头结点开始，依次释放所有结点
	QNode* cur = q->front;

	while (cur != NULL) {
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	// 防止出现野指针
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

bool QueueEmpty(LinkQueue* q) {
	assert(q);
	return q->size == 0;
	//return q->front == q->rear;
}

int QueueSize(LinkQueue* q) {
	assert(q);
	return q->size;
}

QDataType QueueFront(LinkQueue* q) {
	assert(q);
	assert(!QueueEmpty(q));
	return q->front->next->data;
}

void EnQueue(LinkQueue* q, QDataType x) {
	assert(q);

	//申请结点
	QNode* newNode = (QNode*)malloc(sizeof(QNode));

	if (newNode == NULL) {
		perror("malloc fail");
		exit(-1);
	}

	newNode->data = x;
	newNode->next = NULL;
	
	//尾插结点
	q->rear->next = newNode;
	q->rear = newNode;
	q->size++;
}

QDataType DeQueue(LinkQueue* q) {
	// 保证队列指针有效
	assert(q);
	// 空队列不能执行出队操作
	assert(!QueueEmpty(q));

	// 带头结点的队列中，头结点后的第一个结点是队头结点
	QNode* delNode = q->front->next;

	// 释放结点前，先保存队头数据
	QDataType x = delNode->data;

	// 让头结点跳过待删除结点，指向下一个有效结点
	q->front->next = delNode->next;

	// 如果删除的是最后一个有效结点，队列将变为空
	// 此时 rear 需要重新指向作为哨兵的头结点
	if (q->rear == delNode) {
		q->rear = q->front;
	}

	free(delNode);
	q->size--;
	return x;
}