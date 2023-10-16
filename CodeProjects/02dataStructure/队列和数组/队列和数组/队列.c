#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

//循环队列
// 创
#define MaxSize 10
typedef struct {
	int data[MaxSize];
	int front, rear;
}SqQueue;

void InitQueue(SqQueue* Q) {
	Q->front = 0;//头
	Q->rear = 0;//尾
}

//判空
bool QueueEmpty(SqQueue Q) {
	if (Q.rear == Q.front)
		return true;
	else
		return false;
}



// 销

// 增
bool EnQueue(SqQueue* Q, int x) {
	if ((Q->rear+1)%MaxSize==Q->front) // 判断队满
		return false;
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MaxSize;
}
// 删
bool DwQueue(SqQueue* Q, int* x) {
	if (Q->front == Q->rear)
		return false;
	*x = Q->data[Q->front];
	Q->front = (Q->front + 1) % MaxSize;
	return true;
}
// 改

// 查
bool GetHead(SqQueue* Q, int* x)
{
	if (Q->front == Q->rear)
		return false;
	*x = Q->data[Q->front];
	return true;
}


// 队列链式实现
//创(头结点)
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

void InitQueue(LinkQueue *Q) {
	Q->front = Q->rear = (LinkNode*)malloc(sizeof(LinkNode)); //建立头结点
	Q->front->next = NULL;
}

//判空(头结点)
bool IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
//创（无头结点）
void InitQueue2(LinkQueue* Q) {
	Q->front = NULL;
	Q->rear = NULL;
}

//判空（无头结点）
bool IsEmpty(LinkQueue Q) {
	if (Q.front = NULL)
		return true;
	else
		return false;
}

//销

//增(头结点)
void EnQueue(LinkQueue* Q, int x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
}
//增（无头结点）
void EnQueue2(LinkQueue* Q, int x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if (Q->rear == NULL)
	{
		Q->front = s;
		Q->rear = s;
	}
	else {
		Q->rear ->next= s;
		Q->rear = s;
	}
}
//删(头结点)
bool DeQueue(LinkQueue* Q, int *x) {
	if (Q->rear == Q->front)
		return false;
	LinkNode* p = Q->front->next;// 出队结点
	*x = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->front=Q->rear;
	free(p);
	return true;
}
// 删（无头结点）
bool DeQueue2(LinkQueue* Q, int* x) {
	if (Q->front == NULL)
		return false;
	LinkNode* p = Q->front;
	*x = p->data;
	Q->front = p->next;
	if (Q->rear == p) {
		Q->front = NULL;
		Q->rear = NULL;
	}
	free(p);
	return true;

}
//改

//查