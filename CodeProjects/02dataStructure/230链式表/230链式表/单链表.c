#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// http://data.biancheng.net/view/161.html
//������(��ͷ��㣩 https://blog.csdn.net/ZX_ZX_/article/details/107396804


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

//������İ�λ����(��ͷ���)
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

//ǰ���������ͷ��㣩����p���ǰ����Ԫ��e - ��ͬ
//����2����ͷָ��L����ֵ����
bool InsertPoriorNode3(LNode* p, int e)
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));

	if (s == NULL)		//�ڴ����ʧ��
		return false;

	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	return true;
}

//��λ��ɾ����ͷ��㣩
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

	LNode* q = p->next; // ����i���
	p->next = q->next;
	e = q->data;
	free(q);
	return true;


}
//��λ��ɾ������ͷ��㣩
bool ListDelete2(LNode* L, int i, int e)
{
	if (i < 1)
		return false;
	if (1 == i)
	{
		LNode* p = L;
		L = p->next;
		e = p->data;
		free(p);
		return true;
	}

	LNode* p = L;
	int j;
	while (p != NULL && j < i - 1)
	{
		j++;
		p = p->next;
	}
	LNode* q = p->next; // ����i���
	p->next = q->next;
	e = q->data;
	free(q);
	return true;
}

//ɾ��ָ�����p��ͷ��㣩
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
//ɾ��ָ�����p����ͷ��㣩- ��ͬ
bool DeleteNode2(LNode* p)
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
//��λ���ң���ͷ��㣩 - ��ͬ
LNode* GetElem2(LNode* L, int i) 
{
	if (L == NULL)
		return false;
	LNode* p;
	p = L;
	int j = 0;
	while (p != NULL && j < i)
	{
		j++;
		p = p->next;
	}
	return p;
}


//��ֵ���ң�ͷ��㣩
LNode* LocateElem(LNode* L, int e)
{
	LNode* p = L;
	while (p != NULL && p->data != e)
		p = p->next;
	return p;
}
//��ֵ���ң���ͷ��㣩-��ͬ
LNode* LocateElem2(LNode* L, int e)
{
	LNode* p;
	p = L;
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

// β�巨����������ͷ��㣩
LinkList List_TailLnsert(LNode* L)
{
	int x; //����elemtapeΪ����
	L = (LNode*)malloc(sizeof(LNode)); //����ͷ���
	LNode* s, * r = L; //r��ʾ��βָ�� s��ʾ������Ľ��
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}

	s->next = NULL;
	return L;
}
// β�巨������������ͷ��㣩
LinkList List_TailLnsert2(LNode* L)
{
	int x;
	LNode* s, * r = L;
	int i = 1; //��ǵ�һ������Ա��ڸ�ͷָ�븳ֵ
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		if (1 == i)
		{
			s->data = x;
			L = s;
			r = s;
			i = 0;
			scanf("%d", &x);
			continue;
		}
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}

	s->next = NULL;
	return L;

}

// ͷ�巨����������ͷ��㣩
LinkList List_HerdInsert(LNode* L)
{
	int x;
	LNode* s;
	L = (LNode*)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}
// ͷ�巨������������ͷ��㣩
LinkList List_HerdInsert2(LNode* L)
{
	int x;
	L = NULL;
	LNode* s;

	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));

		s->data = x; 
		s->next = L;
		L = s;
		scanf("%d", &x);
		
	}
	return L;
}

int main()
{

	return 0;
}
