#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
//˫����

// ˫����Ķ���

typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode,* DLinkList;  // DLinklist==DNode*

// ��
bool InitDLinkList(DLinkList L) {
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->prior = NULL;
	L->next = NULL;
	return true;
}
// ��
// ��
bool InsertNextNode(DNode* p, DNode* s)
{
	if (p == NULL || s == NULL)
		return false;
	s->next = p->next;
	if(p->next!=NULL)
		p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}
// ɾ
//ɾ��P���ĺ�̽��q
bool DeleteNextDNode(DNode* p) {
	if (p == NULL) return false;
	DNode* q = p->next;
	if (q == NULL) return false;
	p->next = q->next;
	if (q->next != NULL)
		q->next->prior = q->prior;
	free(q);
	return true;
}
// ��

// ��
//�������
bool SearchNode1(DNode* p)
{
	while (p != NULL)
	{
		p = p->next;
	}
}
//ǰ�����
bool SearchNode2(DNode* p)
{
	while (p != NULL)
	{
		p = p->prior;
	}
}
//ǰ�б�������ͷ���
bool SearchNode3(DNode* p)
{
	while (p ->prior!= NULL)
	{
		p = p->next;
	}
}