#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h> 
#include <stdlib.h>

//����������ʽ�洢
typedef struct BiTNode {
	int data; // ������
	struct BiTNode* lchild, * rchild; // ���Һ���ָ��
}BiTNode,*BiTree;



