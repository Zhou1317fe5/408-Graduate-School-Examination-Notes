#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// http://data.biancheng.net/view/161.html
//单链表(无头结点） https://blog.csdn.net/ZX_ZX_/article/details/107396804


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

//单链表的按位插入(无头结点)
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

//前插操作（无头结点）：在p结点前插入元素e - 相同
//方法2：无头指针L，赋值后移
bool InsertPoriorNode3(LNode* p, int e)
{
	if (p == NULL)
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));

	if (s == NULL)		//内存分配失败
		return false;

	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	return true;
}

//按位序删除（头结点）
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

	LNode* q = p->next; // 复制i结点
	p->next = q->next;
	e = q->data;
	free(q);
	return true;


}
//按位序删除（无头结点）
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
	LNode* q = p->next; // 复制i结点
	p->next = q->next;
	e = q->data;
	free(q);
	return true;
}

//删除指定结点p（头结点）
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
//删除指定结点p（无头结点）- 相同
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
//按位查找（无头结点） - 相同
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


//按值查找（头结点）
LNode* LocateElem(LNode* L, int e)
{
	LNode* p = L;
	while (p != NULL && p->data != e)
		p = p->next;
	return p;
}
//按值查找（无头结点）-相同
LNode* LocateElem2(LNode* L, int e)
{
	LNode* p;
	p = L;
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

// 尾插法建立单链表（头结点）
LinkList List_TailLnsert(LNode* L)
{
	int x; //设置elemtape为整形
	L = (LNode*)malloc(sizeof(LNode)); //建立头结点
	LNode* s, * r = L; //r表示表尾指针 s表示代插入的结点
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
// 尾插法建立单链表（无头结点）
LinkList List_TailLnsert2(LNode* L)
{
	int x;
	LNode* s, * r = L;
	int i = 1; //标记第一个结点以便于给头指针赋值
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

// 头插法建立单链表（头结点）
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
// 头插法建立单链表（无头结点）
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
