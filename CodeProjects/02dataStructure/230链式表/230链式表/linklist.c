#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// http://data.biancheng.net/view/161.html

/*������*/

// ������Ķ���
typedef struct LNode { // ���嵥����������
	int data;		// ������
	struct LNode* next; // ָ����
}LNode,*LinkList;

//������İ�λ����-��ͷ���
	// ��i��λ�ò���Ԫ��e
bool ListInsert(LNode* L, int i, int e) 
{
	// ����
	if (i < 1)
		return false;

	LNode* p;
	int j = 0; // ��ǰ���
	p = L;
	//�ҵ�i-1��λ��
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	
	if (p == NULL)
		return false;

	// �ҵ���������
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->next = p->next;
	p->next = s;
	s->data = e;
	return true;

}

//������İ�λ����-����ͷ���
bool ListInsert2(LNode* L, int i, int e)
{
	// ����
	if (i < 1)
		return false;
	//��i=1ʱ
	if (1 == i)
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->next = L;
		L = s;
		s->data = e;
		return true;
	}
	//�ҵ�i-1��λ��
	LNode* p;
	int j = 1; // ��ǰ���
	p = L;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
		
	}

	if (p == NULL)
		return false;

	// �ҵ���������
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->next = p->next;
	p->next = s;
	s->data = e;
	return true;
}

//����������p�������Ԫ��e
bool InsertNextNode(LNode* p,int e)
{
	if (NULL == p)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (NULL == s)
		return false;
	s->next = p->next;
	p->next = s;
	s->data = e;
	return true;
}

//ǰ�������ͷ��㣩����p���ǰ����Ԫ��e
//����1������ͷָ��L
bool InsertPoriorNode1(LNode* L, LNode* p, int e)
{
	if (NULL == p)
		return false;

	// ��p���
	LNode* s = L; //��ǰ���
	LNode* l; //p���ǰһ�����

	do
	{
		l = s;
		s = s->next;
	} while (s != p);
	
	//InsertNextNode(l, e);
	LNode* ins = (LNode*)malloc(sizeof(LNode));
	ins->next = l->next;
	l->next = ins;
	ins->data = e;
	return true;
}


//ǰ�������ͷ��㣩����p���ǰ����Ԫ��e
//����2����ͷָ��L����ֵ����
bool InsertPoriorNode2(LNode* p, int e)
{
	if (NULL == p)
		return false;

	LNode* s = (LNode*)malloc(sizeof(LNode));

	if (NULL == s)
		return false;

	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	return true;

}

//��λ��ɾ������ͷ��㣩
bool ListDelete(LNode* L, int i, int e)
{
	if (i < 1)
		return false;
	LNode* p;
	int j = 0;
	p = L;
	while (p != NULL && j < i)
	{
		j++;
		p = p->next;
	}

	if (p == NULL)
		return false;
	if (p->next == NULL)
		return false;

	LNode* q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return true;


}

//ɾ��ָ�����p
bool DeleteNode(LNode* p)
{
	if (p == NULL)
		return false;
	LNode* q = p->next;
	p->data = q->data;
	p->next = q->next;
	free(q);
	return true;
}

//��λ���ң�ͷ��㣩
LNode* GetElem(LNode* L, int i)
{
	if (L == NULL)
		return NULL;
	LNode* p=L;
	int j = 0;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;

}
//��ֵ����
LNode* LocateElem(LNode* L, int e)
{
	LNode* p = L;
	while (p != NULL && p->data != e)
		p = p->next;
	return p;
}

//�����
int ListLength(LNode* L)
{
	int len = 0;
	LNode* p = L;
	while (p->next != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}


int main()
{




	return 0;
}
