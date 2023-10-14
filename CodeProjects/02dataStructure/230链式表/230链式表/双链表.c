#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
//双链表

// 双链表的定义

typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode,* DLinkList;  // DLinklist==DNode*

// 创
bool InitDLinkList(DLinkList L) {
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->prior = NULL;
	L->next = NULL;
	return true;
}
// 销
// 增
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
// 删
//删除P结点的后继结点q
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
// 改

// 查
//后向遍历
bool SearchNode1(DNode* p)
{
	while (p != NULL)
	{
		p = p->next;
	}
}
//前向遍历
bool SearchNode2(DNode* p)
{
	while (p != NULL)
	{
		p = p->prior;
	}
}
//前行遍历跳过头结点
bool SearchNode3(DNode* p)
{
	while (p ->prior!= NULL)
	{
		p = p->next;
	}
}