#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// 创
#define MAXSize 10
typedef struct {
	int data[MAXSize];
	int top;

}SqStack;

void InitStack(SqStack* S) {
	S->top = -1;
}

void testStack() {
	SqStack s;
	InitStack(&s);
}

//判空
bool StackEmpty(SqStack S) {
	if (S.top == -1)
		return true;
	else
		return false;
}

// 销

// 增
bool PushStack(SqStack* s, int x) {
	if (s->data == MAXSize - 1)
		return false;
	s->top++;
	s->data[s->top] = x;
	return true;
}

// 删
bool PopStack(SqStack* s, int* x) {
	if (s->top == -1)
		return false;
	x = s->data[s->top];
	s->top--;
	return true;
}


// 改

// 查
bool GetTop(SqStack* s, int* x) {
	if (s->top == -1)
		return false;
	x = s->data[s->top];
	return true;
}

// 共享栈
typedef struct {
	int data[MAXSize];
	int top0;
	int top1;
}ShStack;

void IninShStack(ShStack* s) {
	s->top0 = -1;
	s->top1 = MAXSize;
}