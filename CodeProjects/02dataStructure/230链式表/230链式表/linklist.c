#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// http://data.biancheng.net/view/161.html

/*单链表*/

// 单链表的定义
typedef struct LNode { // 定义单链表结点类型
	int data;		// 数据域
	struct LNode* next; // 指针域
}LNode,*LinkList;

//单链表的按位插入-带头结点
	// 第i个位置插入元素e
bool ListInsert(LNode* L, int i, int e) 
{
	// 特判
	if (i < 1)
		return false;

	LNode* p;
	int j = 0; // 当前结点
	p = L;
	//找到i-1个位置
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	
	if (p == NULL)
		return false;

	// 找到后插入操作
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->next = p->next;
	p->next = s;
	s->data = e;
	return true;

}

//单链表的按位插入-不带头结点
bool ListInsert2(LNode* L, int i, int e)
{
	// 特判
	if (i < 1)
		return false;
	//当i=1时
	if (1 == i)
	{
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->next = L;
		L = s;
		s->data = e;
		return true;
	}
	//找到i-1个位置
	LNode* p;
	int j = 1; // 当前结点
	p = L;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
		
	}

	if (p == NULL)
		return false;

	// 找到后插入操作
	LNode* s = (LNode*)malloc(sizeof(LNode));
	s->next = p->next;
	p->next = s;
	s->data = e;
	return true;
}

//后插操作：在p结点后插入元素e
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

//前插操作（头结点）：在p结点前插入元素e
//方法1：传入头指针L
bool InsertPoriorNode1(LNode* L, LNode* p, int e)
{
	if (NULL == p)
		return false;

	// 找p结点
	LNode* s = L; //当前结点
	LNode* l; //p结点前一个结点

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


//前插操作（头结点）：在p结点前插入元素e
//方法2：无头指针L，赋值后移
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

//按位序删除（带头结点）
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

//删除指定结点p
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

//按位查找（头结点）
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
//按值查找
LNode* LocateElem(LNode* L, int e)
{
	LNode* p = L;
	while (p != NULL && p->data != e)
		p = p->next;
	return p;
}

//求表长度
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
