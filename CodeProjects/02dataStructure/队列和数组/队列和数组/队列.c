#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

//ѭ������
// ��
#define MaxSize 10
typedef struct {
	int data[MaxSize];
	int front, rear;
}SqQueue;

void InitQueue(SqQueue* Q) {
	Q->front = 0;//ͷ
	Q->rear = 0;//β
}

//�п�
bool QueueEmpty(SqQueue Q) {
	if (Q.rear == Q.front)
		return true;
	else
		return false;
}



// ��

// ��
bool EnQueue(SqQueue* Q, int x) {
	if ((Q->rear+1)%MaxSize==Q->front) // �ж϶���
		return false;
	Q->data[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MaxSize;
}
// ɾ
bool DwQueue(SqQueue* Q, int* x) {
	if (Q->front == Q->rear)
		return false;
	*x = Q->data[Q->front];
	Q->front = (Q->front + 1) % MaxSize;
	return true;
}
// ��

// ��
bool GetHead(SqQueue* Q, int* x)
{
	if (Q->front == Q->rear)
		return false;
	*x = Q->data[Q->front];
	return true;
}


// ������ʽʵ��
//��(ͷ���)
typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

void InitQueue(LinkQueue *Q) {
	Q->front = Q->rear = (LinkNode*)malloc(sizeof(LinkNode)); //����ͷ���
	Q->front->next = NULL;
}

//�п�(ͷ���)
bool IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}
//������ͷ��㣩
void InitQueue2(LinkQueue* Q) {
	Q->front = NULL;
	Q->rear = NULL;
}

//�пգ���ͷ��㣩
bool IsEmpty(LinkQueue Q) {
	if (Q.front = NULL)
		return true;
	else
		return false;
}

//��

//��(ͷ���)
void EnQueue(LinkQueue* Q, int x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
}
//������ͷ��㣩
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
//ɾ(ͷ���)
bool DeQueue(LinkQueue* Q, int *x) {
	if (Q->rear == Q->front)
		return false;
	LinkNode* p = Q->front->next;// ���ӽ��
	*x = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->front=Q->rear;
	free(p);
	return true;
}
// ɾ����ͷ��㣩
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
//��

//��