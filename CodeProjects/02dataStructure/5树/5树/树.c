#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h> 
#include <stdlib.h>

//����������ʽ�洢
typedef struct BiTNode {
	int data; // ������
	struct BiTNode* lchild, * rchild; // ���Һ���ָ��
}BiTNode,*BiTree;

<<<<<<< HEAD
=======
BiTNode* root = NULL;
root = (BiTNode*)malloc(sizeof(BiTNode));
>>>>>>> 5f4c2a4891d4531de7d6cffd16f1cb4e1fa9868e


